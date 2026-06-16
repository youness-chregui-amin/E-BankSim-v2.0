#pragma once
#include <iostream>
#include "User.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";

    }
    static bool CheckAccessRights(clsUser::enPermission Permission)
    {




        if (!CurrentUser.CheckAccessPermission(Permission))
        {

            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;


        }
        else
        {
            return true;

        }
    }
    static void _DrawScreenHeaderMain()
    {
        cout << "\t\t\t\t\t______________________________________\n";

        cout << R"(

				     __       ___             _     __ _           
				    /__\     / __\ __ _ _ __ | | __/ _(_)_ __ ___  
				   /_\_____ /__\/// _` | '_ \| |/ /\ \| | '_ ` _ \ 
				  //_|_____/ \/  \ (_| | | | |   < _\ \ | | | | | |
				  \__/     \_____/\__,_|_| |_|_|\_\\__/_|_| |_| |_|

)";

        cout << "\t\t\t\t\t______________________________________\n\n";
    }
    static void IsNowUser()
    {
        
         
        cout << "\t\t\t\t\t\t       User: " << CurrentUser.UserName << endl;

    }

    static void PrintCurrentDateTime()
    {
        time_t t = time(nullptr);
        tm now;
        localtime_s(&now, &t);

        cout << "\t\t\t\t\t\t      Date: "
            << now.tm_mday << "/"
            << now.tm_mon + 1 << "/"
            << now.tm_year + 1900 << endl;

        cout << "\t\t\t\t\t\t      Time: "
            << now.tm_hour << ":"
            << now.tm_min << ":"
            << now.tm_sec << endl;
    }
};