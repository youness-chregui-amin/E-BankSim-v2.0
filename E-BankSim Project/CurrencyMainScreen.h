#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include <iomanip>
#include "CurrenciesListScreen.h"
#include "FindCurrencyScreen.h"
#include "UpdateCurrencyRateScreen.h"
#include "CurrencyCalculatorScreen.h"

class clsCurrencyMainScreen : protected clsScreen
{

private:

	
	enum enCurrencyMainScreen {eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3 ,
		eCurrencyCalculator = 4, eMainMenue= 5};

	static short _ReadCurrencyMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? > ";

		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? > ");
		return Choice;

	}
	static void _GoBackToMainMenue()
	{

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyMainMenue();


	}
	static void _ShowListCurrenciesScreen()
	{

		clsCurrenciesListScreen::ShowListScreen();

	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrencyScreen();

	}
	static void _ShowUpdateRateScreen()
	{

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();

	}
	static void _ShowCurrencyCalculatorScreen()
	{

		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();


	}
	static void _GoBackToCurrencyMainMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowCurrencyMainMenue();

	}


	static void _PerfromCurrencyMainMenueOption(enCurrencyMainScreen CurrencyMainScreen)
	{
		switch (CurrencyMainScreen)
		{
			case enCurrencyMainScreen::eListCurrencies:
			{
				system("cls");
				_ShowListCurrenciesScreen();
				_GoBackToCurrencyMainMenue();
				break;
			}
			case enCurrencyMainScreen::eFindCurrency:
			{

				system("cls");
				_ShowFindCurrencyScreen();
				_GoBackToCurrencyMainMenue();
				break;

			}
			case enCurrencyMainScreen::eUpdateRate:
			{

				system("cls");
				_ShowUpdateRateScreen();
				_GoBackToCurrencyMainMenue();
				break;

			}
			case enCurrencyMainScreen::eCurrencyCalculator:
			{

				system("cls");
				_ShowCurrencyCalculatorScreen();
				_GoBackToCurrencyMainMenue();
				break;


			}
			case enCurrencyMainScreen::eMainMenue:
			{



			}


	    }

	}

public:

	static void ShowCurrencyMainMenue()
	{

		if (!CheckAccessRights(clsUser::enPermission::eCurrencyExhange))
		{

			return;
		}

		system("cls");
		_DrawScreenHeader("Currency Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Main Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Clients .\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrencyMainMenueOption(enCurrencyMainScreen(_ReadCurrencyMainMenueOption()));
	}




};
