#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "CSVFileOperation.h"
#include "BankMgtUtilities.h"

CSVFileOperations::CSVFileOperations()
{
	m_eErrorCode = E_AS_NO_ERROR;
	m_SerialNoForCustFile = 0;
}

CSVFileOperations::~CSVFileOperations()
{

}

ASErrorCodeType CSVFileOperations::AS_OpenCSVFile(string filename, FILE *logfileWriter, string operationType)
{
	ASErrorCodeType errorCode = E_AS_NO_ERROR;

	try
	{
		if (operationType == "Read")
		{

		}
		else 
		{
			m_filewriter.open(filename, std::ofstream::out);
		}
	}
	catch (std::exception ex)
	{
		fprintf(logfileWriter, "%s:[%d] Exception in Opening file for Write = %s", __FUNCTION__, __LINE__, ex.what());
		errorCode = E_AS_NOT_FOUND;
	}

	return errorCode;
}

ASErrorCodeType CSVFileOperations::AS_CloseCSVFile(FILE *logfileWriter, string operationType)
{
	ASErrorCodeType errorCode = E_AS_NO_ERROR;

	try
	{
		if (operationType == "Read")
		{

		}
		else
		{
			m_filewriter.close();
		}
	}
	catch (std::exception ex)
	{
		fprintf(logfileWriter, "%s:[%d] Exception in Opening file for Write = %s", __FUNCTION__, __LINE__, ex.what());
		errorCode = E_AS_NOT_FOUND;
	}

	return errorCode;

}


ResultStatusType CSVFileOperations::AS_ReadCSVFile(string filename)
{

	ResultStatusType eStatus = E_STATUS_SUCCESS;
	ASErrorCodeType errorCode = E_AS_NO_ERROR;

	errorCode = AS_OpenCSVFile(filename);
	if (errorCode == E_AS_NO_ERROR)
	{




		
		
	}

	if (errorCode != E_AS_NO_ERROR)
	{
		m_eErrorCode = errorCode;
		eStatus = E_STATUS_FAILURE;
	}
	return eStatus;
}


ResultStatusType CSVFileOperations::AS_WriteIntoCSVFile(string filename, FILE *logfileWriter, vector<string> *record)
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;
	ASErrorCodeType errorCode = E_AS_NO_ERROR;

	errorCode = AS_OpenCSVFile(filename, logfileWriter, "Write");
	if (errorCode == E_STATUS_SUCCESS)
	{
		GetLastSerialNumber(filename, logfileWriter);
		for (int indx = 0; indx < record->size()-1; indx++)
		{
			m_filewriter << record->at(indx) << " , ";
		}
		m_filewriter << record->at(record->size() - 1) << endl;
	
		AS_CloseCSVFile(logfileWriter, "Write");
	}

	if (errorCode != E_AS_NO_ERROR)
	{
		m_eErrorCode = errorCode;
		eStatus = E_STATUS_FAILURE;
	}
	return eStatus;
}

ResultStatusType CSVFileOperations::AS_CheckIfAccountNumberExists(int AccNo, FILE *logfilewriter, string filename,  bool *IsAccNoExists)
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;
	ASErrorCodeType errorCode = E_AS_NO_ERROR;




	if (errorCode != E_AS_NO_ERROR)
	{
		m_eErrorCode = errorCode;
		eStatus = E_STATUS_FAILURE;
	}
	return eStatus;
}



ASErrorCodeType CSVFileOperations::GetLastSerialNumber(string filename, FILE *logfileWriter)
{
	ifstream freader(filename, std::ios::in);
	vector<string> rec;
	string line;
	stringstream ss;
	string srNo;
	if (freader.is_open())
	{
		while (getline(freader, line))
		{
			ss << line;
			getline(ss, srNo, ',');
			m_SerialNoForCustFile = stoi(srNo);
		}
		fprintf(logfileWriter, "%s:[%d] last Serial No = %d ", __FUNCTION__, __LINE__,  m_SerialNoForCustFile);
		freader.close();
	}
}