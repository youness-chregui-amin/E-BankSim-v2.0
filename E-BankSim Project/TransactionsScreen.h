#pragma once
#include <iostream>
#include "Screen.h"
#include "BankClient.h"
#include "InputValidation.h"
#include "MainScreen.h"
#include "DepositScreen.h"
#include "WithdrawScreen.h"
#include "TotalBalanceScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"


using namespace std;


class clsTransactionsScreen : protected clsScreen
{

private:


	enum enTransactionsMenueOptions { eDepositScreen = 1, eWithdrawScreen = 2, eTotalBalanceScreen = 3, eTransfer = 4 ,eTransfesLog = 5 , eMainMenue = 6 };

    static short _ReadTransactionsMenueOption()
    {
	 cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? > ";

	 short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 6? > ");
	 return Choice;

    }
	static void _GoBackTomainMenue()
	{

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowTransactionsMenue();


	}
	static void _ShowDepositScreen()
	{

		clsDepositScreen::ShowDepositScreen();

	}
	static void _ShowWithdrawScreen()
	{

		clsWithdrawScreen::ShowWithdrawScreen();

	}
	static void _ShowTotalBalanceScreen()
	{

		clsTotalBalanceScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{

		clsTransferScreen::ShowTransferScreen();

	}
	static void _ShowTransferLogScreen()
	{

		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();

	}

	static void _PerfromTransactionsMainMenueOption(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions::eDepositScreen:
		   {
			   system("cls");
			   _ShowDepositScreen();
			   _GoBackToTransactionsMenue();

		   }
		   case enTransactionsMenueOptions::eWithdrawScreen:
		   {
			   system("cls");
			   _ShowWithdrawScreen();
			   _GoBackToTransactionsMenue();
			   break;

		   }
		   case enTransactionsMenueOptions::eTotalBalanceScreen:
		   {
			   system("cls");
			   _ShowTotalBalanceScreen();
			   _GoBackToTransactionsMenue();
			   break;


		   }
		   case enTransactionsMenueOptions::eTransfer:
		   {
			   system("cls");
			   _ShowTransferScreen();
			   _GoBackToTransactionsMenue();
			   break;


		   }
		   case enTransactionsMenueOptions::eTransfesLog:
		   {

			   system("cls");
			   _ShowTransferLogScreen();
			   _GoBackToTransactionsMenue();
			   break;

		   }
		   case enTransactionsMenueOptions::eMainMenue:
		   {

			   

		   }


		}





	}

public:

	static void ShowTransactionsMenue()
	{

		if (!CheckAccessRights(clsUser::enPermission::pTranactions))
		{

			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromTransactionsMainMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

	

};

