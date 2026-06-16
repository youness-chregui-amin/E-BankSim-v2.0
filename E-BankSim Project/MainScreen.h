#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "ClientListScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsScreen.h"
#include "ManageUsersLib.h"
#include "RegisterLoginScreen.h"
#include "CurrencyMainScreen.h"
#include <iomanip>
using namespace std;

class clsMainScreen : protected clsScreen 
{
private:

	enum eMainMenueOptions { eListClients = 1, eAddNewClient = 2, 
		eDeletClient = 3, eUpdateClient = 4, eFindClient = 5 ,
		eShowTransactionMenue = 6 , eManageUsers = 7 , eLoginRegister = 8 , eCurrencyExhange = 9, eExit = 10 };
	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? > ";

		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? > ");
		return Choice;

	}
	static void _GoBackToMainMenue()
	{

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();

	}
	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();


	}
	static void _ShowAddNewClientsScreen()
	{

		clsAddNewClientScreen::AddNewClinetScreen();


	}
	static void _ShowDeleteClientScreen()
	{

		clsDeleteClientScreen::DeleteClientScreen();
	}
	static void _ShowUpdateClientScreen()
	{

		clsUpdateClientScreen::UpdateClientScreen();


	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClientScreen();

	}
	static void _ShowTransactionsMenue()
	{

		
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	static void _ShowManageUsersMenue()
	{

		clsManageUsers::ShowManagerUsersMenue();

	}
	static void _ShowLoginRegister()
	{

		clsRegisterLoginScreen::ShowLoginRegisterScreen();

	}
	static void _ShowCurrencyExhangeScreen()
	{

		clsCurrencyMainScreen::ShowCurrencyMainMenue();
	}
	static void _Logout()
	{

		CurrentUser = clsUser::Find("", "");

	}

	static void _PerfromMainMenueOption(eMainMenueOptions  MainMenueOptions)
	{

		switch (MainMenueOptions)
		{
			case eMainMenueOptions::eListClients:
			{
				system("cls");
				_ShowAllClientsScreen();
				_GoBackToMainMenue();
				break;

			}
			case eMainMenueOptions::eAddNewClient:
			{
				system("cls");
				_ShowAddNewClientsScreen();
				_GoBackToMainMenue();
				break;


			}
			case eMainMenueOptions::eDeletClient:
			{
				system("cls");
				_ShowDeleteClientScreen();
				_GoBackToMainMenue();
				break;


			}
			case eMainMenueOptions::eUpdateClient:
			{

				system("cls");
				_ShowUpdateClientScreen();
				_GoBackToMainMenue();
				break;


			}
			case eMainMenueOptions::eFindClient:
			{

				system("cls");
				_ShowFindClientScreen();
				_GoBackToMainMenue();
				break;

			}
			case eMainMenueOptions::eShowTransactionMenue:
			{
				system("cls");
				_ShowTransactionsMenue();
				_GoBackToMainMenue();
				break;
			}
			case eMainMenueOptions::eManageUsers:
			{
				system("cls");
				_ShowManageUsersMenue();
				_GoBackToMainMenue();
				break;

			}
			case eMainMenueOptions::eLoginRegister:
			{

				system("cls");
				_ShowLoginRegister();
				_GoBackToMainMenue();
				break;

			}
			case eMainMenueOptions::eCurrencyExhange:
			{

				system("cls");
				_ShowCurrencyExhangeScreen();
				_GoBackToMainMenue();
				break;

			}
			case eMainMenueOptions::eExit:
			{
				system("cls");
				_Logout();
				break;


			}


		}



	}



	public:


	static void ShowMainMenue()
	{

		system("cls");
		clsScreen::_DrawScreenHeaderMain();
		clsScreen::IsNowUser();
		clsScreen::PrintCurrentDateTime();
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1]  Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2]  Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3]  Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4]  Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5]  Find Client.\n";
		cout << setw(37) << left << "" << "\t[6]  Transactions.\n";
		cout << setw(37) << left << "" << "\t[7]  Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8]  Login Register.\n";
		cout << setw(37) << left << "" << "\t[9]  Currency Exhange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((eMainMenueOptions)_ReadMainMenueOption());

	}






















};

