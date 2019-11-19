#include "BankMgtUtilities.h"

ASErrorCodeType gErrorCode = E_AS_NO_ERROR;
FILE *g_logfileWriter = NULL;
char g_accType[2][10] = { "Saving", "Current" };
int g_serialNo = 0;

ResultStatusType AS_ProgramInit(char *logfile)
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;
	ASErrorCodeType errorCode = E_AS_NO_ERROR;

	//Creating log file
	g_logfileWriter = fopen(logfile, "a+");
	if (g_logfileWriter == NULL)
	{
		g_logfileWriter = fopen(logfile, "w+");
	}
	else
	{
		fprintf(g_logfileWriter, "%s:[%d] log file instance Created \n", __FUNCTION__, __LINE__);
	}


	if (errorCode != E_AS_NO_ERROR)
	{
		eStatus = E_STATUS_FAILURE;
		gErrorCode = errorCode;
	}

	return eStatus;
} 


ResultStatusType AS_RegisterUser()
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;
	ASErrorCodeType errorCode = E_AS_NO_ERROR;
	int accountNo;
 	CustomerInfoType *tempNode;

	FILE *fp_custInfoWriter;
	fp_custInfoWriter = fopen(g_custInfoFilePath, "a+");
	if (fp_custInfoWriter == NULL)
	{
		fprintf(g_logfileWriter, "%s:[%d] Customer Information file opening failed \n ", __FUNCTION__, __LINE__);
		errorCode = E_AS_NOT_FOUND;
	}
	else
	{
		tempNode = createNode();
		errorCode = generateAccountNumber(&accountNo);
		if (!CheckIfAccountIsExists(accountNo))
		{
			tempNode->AccNo = accountNo;

			printf("Enter customer name\n");
			getchar();
			fgets(tempNode->name, 20, stdin);

			printf("Enter Aadhar Number\n");
			fgets(tempNode->AadharNo, 20, stdin);
				
			printf("Enter address \n");
			fgets(tempNode->address, 60, stdin);
				
			printf("Enter profession \n");
			fgets(tempNode->profession, 20, stdin);
				
			int preferAccount;
			printf("Enter type of account to open\n");
			printf("======================\n");
			printf("=                    =\n");
			printf("=                    =\n");
			printf("= 0. Saving Account  =\n");
			printf("= 1. Current Account =\n");
			printf("=                    =\n");
			printf("=                    =\n");
			printf("======================\n");
			scanf("%d", &preferAccount);
			tempNode->accountType = g_accType[preferAccount];
				
			printf("Enter Mobile number \n");
			scanf("%ld", &tempNode->MobNo);
				
			tempNode->balance = 500;

			g_serialNo += 1;
			fprintf(fp_custInfoWriter, "%d,%d,%s,%s,%s,%s,%s,%ld,%f\n", g_serialNo, tempNode->AccNo,
				tempNode->name, tempNode->AadharNo, tempNode->address, tempNode->profession,
				tempNode->accountType, tempNode->MobNo, tempNode->balance);
			fclose(fp_custInfoWriter);

			fprintf(g_logfileWriter, "%s:[%d] Account register successfully \n", __FUNCTION__, __LINE__);
			
		}
		else
		{
			fprintf(g_logfileWriter, "%s:[%d] Account Number %d is already exists \n", __FUNCTION__, __LINE__, accountNo);
		}
	}

 	if (errorCode != E_AS_NO_ERROR)
 	{
 		gErrorCode = errorCode;
 		eStatus = E_STATUS_FAILURE;
 	}
 	
 	return eStatus;
 }

ResultStatusType  AS_AppicationExit()
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;

	fclose(g_logfileWriter);

	return eStatus;
}


bool CheckIfAccountIsExists(int accountNo)
{
	CustomerInfoType *node;
	FILE *fp;
	fp = fopen(g_custInfoFilePath, "r");
	if (fp != NULL)
	{
		fseek(fp, 0, SEEK_SET);
		while (fp != EOF)
		{

		}
		
	}
	
	return false;
}


CustomerInfoType* createNode()
{
	CustomerInfoType *n1;
	do
	{
		n1 = (struct CustomerInfoType *)malloc(sizeof(struct CustomerInfoType));
		n1->next = NULL;
	} while (n1 == NULL);

	return n1;
}

//Function which generates account number for customer
ASErrorCodeType generateAccountNumber(int *accNO)
{
	ASErrorCodeType errorCode = E_AS_NO_ERROR;
	int minlimit = 10000000;
	int maxlimit = 99999999;

	*accNO = (rand() % maxlimit - minlimit + 1) + minlimit;

	return errorCode;
}



