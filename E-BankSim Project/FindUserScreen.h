#pragma once
#include <iostream>
#include "User.h"
#include "Screen.h"
#include "ManageUsersLib.h"
#include <iomanip>
using namespace std;

class clsFindUserScreen : protected clsScreen
{

private:

	static void _PrintUserInfo(clsUser& User)
	{

			cout << "\nUser Card:";
			cout << "\n___________________";
			cout << "\nFirstName   : " << User.FirstName;
			cout << "\nLastName    : " << User.LastName;
			cout << "\nFull Name   : " << User.FullName();
			cout << "\nEmail       : " << User.Email;
			cout << "\nPhone       : " << User.Phone;
			cout << "\nUser Name   : " << User.UserName;
			cout << "\nPassword    : " << User.Password;
			cout << "\nPermissions : " << User.Permissions;
	     	cout << "\n___________________\n";


	}

public:


	static void FindClientScreen()
	{


		_DrawScreenHeader("\t Find User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName Account Number > ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{

			cout << "\ UserName is not found, chose > ";
			UserName = clsInputValidate::ReadString();


		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{

			cout << "\nUser Found :-)\n";

		}
		else
		{
			cout << "\nUser Was not Found :-(\n";

		}

		_PrintUserInfo(User);

	}




};
