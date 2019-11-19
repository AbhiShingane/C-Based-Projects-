#pragma once




#include <dos.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;


static char g_logfilePath[100] = "C:/Users/abhil/OneDrive/Documents/BankManagementLogs/log";
static char g_custInfoFilePath[100] = "C:/Users/abhil/OneDrive/Documents/BankManagementLogs";

typedef enum
{
	E_SAVING_ACCOUNT = 0,
	E_CURRENT_ACCOUNT = 1
}AccountType;


struct CustomerInfoType
{
	int AccNo;
	char name[20];
	char AadharNo[20];
	char address[60];
	char profession[20];
	char *accountType;
	long int MobNo;
	double balance;
	struct CustomerInfoType *next;

};



enum ResultStatusType
{
	E_STATUS_SUCCESS = 0,
	E_STATUS_FAILURE = 1
	
};

enum ASErrorCodeType
{
	E_AS_NO_ERROR = 0,
	E_AS_INVALID_PARAMS = 1,
	E_AS_MEMORY_ALLOCATION_FAILED = 2,
	E_AS_NOT_FOUND = 3,
	E_AS_INVALID_SEQUENCE = 4
};





ResultStatusType AS_ProgramInit(char *logfile);

ResultStatusType AS_RegisterUser();

ResultStatusType AS_AppicationExit();

ASErrorCodeType generateAccountNumber(int *accNO);
CustomerInfoType* createNode();
bool CheckIfAccountIsExists(int accountNo);

