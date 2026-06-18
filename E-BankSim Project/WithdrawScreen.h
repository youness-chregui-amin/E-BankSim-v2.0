#pragma once
#include <iostream>
#include "Screen.h"
#include "BankClient.h"
#include "InputValidation.h"


class clsWithdrawScreen : protected clsScreen
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
            cout << "\nPlease enter Withdraw amount? > ";
            Amount = clsInputValidate::ReadDblNumber();

        } while (Amount <= 0);

        return Amount;
    }


public:


    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        double Amount = _ReadAmount();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Withdraw(Amount))
            {
                cout << "\nAmount Withdrawn Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insufficient Balance!\n";
                cout << "\nAmount to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client1.AccountBalance;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};