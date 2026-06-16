#pragma once
#include "Screen.h"
#include "BankClient.h"
#include "InputValidation.h"
using namespace std;



class clsFindClientScreen : protected clsScreen
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


	static void FindClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermission::pFindClient))
		{
			return;

		}

		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter clinet Account Number > ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount numbe is not found, chose > ";
			AccountNumber = clsInputValidate::ReadString();


		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{

			cout << "\nClient Found :-)\n";

		}
		else
		{
			cout << "\nClient Was not Found :-(\n";

		}

		_PrintClientInfo(Client);

	}


};

