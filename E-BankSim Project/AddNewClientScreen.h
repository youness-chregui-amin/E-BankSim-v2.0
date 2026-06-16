#pragma once
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
#include "InputValidation.h"
using namespace std;
class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClinetInfo(clsBankClient& Client)
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

	static void AddNewClinetScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t  Add New Client Screen");
		string AccountNumber = "";

		cout << "\nPlease Enter clinet Account Number > ";

		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount Numbe Is Already Used, chose another one > ";
			AccountNumber = clsInputValidate::ReadString();


		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClinetInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();
		switch (SaveResult)
		{

		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClientInfo(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}

		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;


		}
		}


	}


};

