#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "BankClient.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{

private:

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << "\t| "
            << setw(8) << left << Client.AccountNumber() << "| "
            << setw(20) << left << Client.FullName() << "| "
            << setw(23) << left << Client.Email << "| "
            << setw(12) << left << Client.Phone << "| "
            << setw(6) << left << Client.PinCode << "|$"
            << setw(8) << left << Client.AccountBalance << "|\n";
    }

public:

    

    static void ShowClientsList()
    {

        if (!CheckAccessRights(clsUser::enPermission::pListClients))
        {

            return;
        }



        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t==========================================================================================\n";

        cout << "\t| "
            << setw(8) << left << "Account"

            << "| "
            << setw(20) << left << "Name"

            << "| "
             << setw(23) << left << "Email" 

            << "| "
          << setw(12) << left << "Phone"

            << "| "
            << setw(6) << left << "PIN"

            << "| "
            << setw(8) << left << "Balance"

            << "|\n";

        cout << "\t==========================================================================================\n";

        if (vClients.size() == 0)
        {
            cout << "\n\t\tNo Clients Available In the System!\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                PrintClientRecordLine(Client);
            }
        }

        cout << "\t==========================================================================================\n";
    }
};