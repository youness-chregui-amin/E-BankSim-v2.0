#pragma once
#include <iostream>
#include "InputValidation.h"
#include "BankClient.h"
#include "Screen.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:


	static void _PrintClientInfo(clsBankClient& Client)
	{

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}


public:

	static void DeleteClientScreen()
	{
		_DrawScreenHeader("\t Delete Client Screen. ");
		string AccountNumber = "";
		cout << "Please Enter Account Number > ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, chose another one > ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Clinet1 = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Clinet1);

		cout << "\nAre you sure you want to delete this client y/n? > ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			if (Clinet1.Delete())
			{

				cout << "\nClinet Deleted Successfuly :-)\n";
				_PrintClientInfo(Clinet1);
			}
			else
			{

				cout << "\nError Clinet was not Deleted\n";

			}

		}

	}

	
};

