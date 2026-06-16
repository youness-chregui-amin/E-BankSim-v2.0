#pragma once
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
#include <iomanip>
#include "UtilLib.h"
using namespace std;


class clsTotalBalanceScreen : protected clsScreen
{
private:


	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{

		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public:

	static void ShowTotalBalances()
	{

		vector <clsBankClient> vClient = clsBankClient::GetClientsList();
		string Titel = "\t Balance List Screen";
		string SubTitle = "\t (" + to_string(vClient.size()) + ") Client(s).";

		_DrawScreenHeader(Titel, SubTitle);


		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClient.size() == 0)
		{

			cout << "\t\t\t\tNo Clients Available In the System!";


		}
		else
		{

			for (clsBankClient Client : vClient)
			{

				_PrintClientRecordBalanceLine(Client);
				cout << endl;

			}



		}
		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t    Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t ( " << clsUtil::NumberToText(TotalBalances) << ")";
	}


};




