#include "BankMgtUtilities.h"
using namespace std;
//using namespace date;
//using namespace 

int main()
{
	ResultStatusType eStatus = E_STATUS_SUCCESS;
	char logfilepath[500];
	time_t currentTime = time(0);
	struct tm *currentDate = localtime(&currentTime);
	
	sprintf(logfilepath, "%s/%d-%d-%d.txt", g_logfilePath, currentDate->tm_mday, (currentDate->tm_mon + 1) , (currentDate->tm_year + 1900));
	
	eStatus = AS_ProgramInit(logfilepath);

	int choice = 0;
	while (1)
	{
		printf("\n ********************** -> Banking Application <- ****************************");
		printf("\n 1: Register an Account");
		printf("\n 2: Withdraw money");
		printf("\n 3: Deposite money");
		printf("\n 4: Fixed Deposite");
		printf("\n 5: Close account");
		printf("\n 6: Get Account statement");
		printf("\n 7: View All accounts");
		printf("\n 0: Closing the Application");
		printf("\n \t ENTER THE CHOICE");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			eStatus = AS_RegisterUser();
			if (eStatus != E_STATUS_SUCCESS)
			{
				printf("Operation failed.. try again");
			}
			break;

		case 0:
			eStatus = AS_AppicationExit();
			if (eStatus != E_STATUS_SUCCESS)
			{
				printf("Operation failed.. try again");
			}
			goto EXIT_LBL;

		case 2:
			//WithDraw();
			break;

		case 3:
			//Deposite();
			break;

		case 4: 
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			//DisplayAllAccounts();
			break;

		default:
			printf("Enter a valid choice");
		}

	}



	EXIT_LBL:
	

	return 0;
}
