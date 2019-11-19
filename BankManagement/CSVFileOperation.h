
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "BankMgtUtilities.h"

#ifndef _CSVFILE_OPERATIONS_H_
#define __CSVFILE_OPERATIONS_H_

using namespace std;

class CSVFileOperations
{
private:
	string m_fileName;
	ASErrorCodeType m_eErrorCode;
	ofstream m_filewriter;
	ifstream m_fileReader;
	int m_SerialNoForCustFile; // denoting Serial No in Customer Info file

public:
	CSVFileOperations();
	ResultStatusType AS_ReadCSVFile(string filename);
	ResultStatusType AS_WriteIntoCSVFile(string filename);
	ResultStatusType AS_CheckIfAccountNumberExists(int AccNo, FILE *logfilewriter, string filename, bool *IsAccNoExists);
	~CSVFileOperations();

private:
	ASErrorCodeType AS_OpenCSVFile(string filename, FILE *logfileWriter, string operationType);
	ASErrorCodeType AS_CloseCSVFile(FILE *logfileWriter, string operationType);
	ASErrorCodeType GetLastSerialNumber(string filename, FILE *logfileWriter);

};


#endif _CSVFILE_OPERATIONS_H_
#pragma once
