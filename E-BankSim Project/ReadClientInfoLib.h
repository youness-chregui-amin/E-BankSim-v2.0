#pragma once
#include <iostream>
#include "BankClientLib.h"
#include "InputValidationLib.h"

class clsReadClientInfo : protected clsBankClient
{
public:

	static void ReadClientInfo(clsBankClient& Clinet)
	{
		cout << "Enter Your Firstname > ";
		Clinet.FirstName = clsInputValidate::ReadString();

		cout << "Enter Your Lastname > ";
		Clinet.LastName = clsInputValidate::ReadString();

		cout << "Enter Your Phone > ";
		Clinet.Phone = clsInputValidate::ReadString();

		cout << "Enter Your Email > ";
		Clinet.Email = clsInputValidate::ReadString();

		cout << "Enter Your PinCode > ";
		Clinet.PinCode = clsInputValidate::ReadString();


		cout << "Enter Your Account Balance > ";
		Clinet.AccountBalance = clsInputValidate::ReadFloatNumber();

	}




};

