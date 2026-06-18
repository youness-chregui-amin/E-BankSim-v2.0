#pragma once
#include <iostream>
#include "InputValidation.h"
#include "Screen.h"
#include "BankClient.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:


	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter Your Firstname > ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter Your Lastname > ";
		Client.LastName = clsInputValidate::ReadString();

		
		cout << "Enter Your Email > ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Your Phone > ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter Your PinCode > ";
		Client.PinCode = clsInputValidate::ReadString();


		cout << "Enter Your Account Balance > ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();



	}

	static void _PrintClientInfo(clsBankClient Client)
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

	static void UpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::pUpdateClients))
		{
			return;
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter clinet Account Number > ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount numbe is not found, chose > ";
			AccountNumber = clsInputValidate::ReadString();


		}


		clsBankClient Clinet1 = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Clinet1);


		cout << "\n\nUpdate Clinet Info > ";
		cout << "\n______________________\n";


		_ReadClientInfo(Clinet1);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Clinet1.Save();


		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{

			cout << "\nAccount Updated Successfull ;-)\n";
			_PrintClientInfo(Clinet1);
			break;
		}

		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}


		}





	}



};

