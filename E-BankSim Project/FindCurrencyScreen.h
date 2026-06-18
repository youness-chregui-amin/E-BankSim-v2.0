#pragma once
#include <iostream>
#include"Currency.h"
#include "InputValidation.h"
#include "Screen.h"
#include <iomanip>


class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrency(clsCurrency &Currency)
	{

		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$)    : " << Currency.Rate();
		cout << "\n___________________\n";



	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:


	static void  FindCurrencyScreen()
	{

		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country > ";
		short Answer = clsInputValidate::ReadIntNumberBetween(1, 2, "\nEnter Number between 1 to 2? >");

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}



	}


};