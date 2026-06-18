#pragma once
#include <iostream>
#include "BankClient.h"
#include "InputValidation.h"
#include "Screen.h"




class clsDepositScreen : protected clsScreen
{
private:

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

    static string _ReadAccountNumber()
    {

        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? > ";
        cin >> AccountNumber;
        return AccountNumber;


    }
    static double _ReadAmount()
    {
        double Amount;
        do
        {
            cout << "\nPlease enter deposit amount? > ";
            Amount = clsInputValidate::ReadDblNumber();

        } while (Amount <= 0);

        return Amount;
    }

public:


    static void ShowDepositScreen()
    {

        _DrawScreenHeader("\t Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {

            cout << "\nClient with [" << AccountNumber << "] does not exist\n";
            AccountNumber = _ReadAccountNumber();

        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        double Amount = _ReadAmount();
        cout <<"\nAre you sure you want to perform this transaction? " ;
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {

            Client1.Deposit(Amount);
            cout << "\nAmount Deposited SuccessFully.\n";
            cout << "\nNew Balance is : " << Client1.AccountBalance;


        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }


    }



};

