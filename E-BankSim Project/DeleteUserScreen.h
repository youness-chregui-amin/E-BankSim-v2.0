#pragma once
#include <iostream>
#include "Screen.h"
#include "ManageUsersLib.h"
#include "InputValidation.h"
#include <iomanip>
using namespace std;

class clsDeleteUserScreen : protected clsScreen
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


	static void DeleteUserScreen()
	{

		if (!CheckAccessRights(clsUser::enPermission::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t Delete User Screen. ");
		string UserName = "";
		cout << "Please Enter UserName > ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is not found, chose another one > ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUserInfo(User1);

		cout << "\nAre you sure you want to delete this User y/n? > ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			if (User1.Delete())
			{

				cout << "\nUser Deleted Successfuly :-)\n";
				_PrintUserInfo(User1);
			}
			else
			{

				cout << "\nError User was not Deleted\n";

			}

		}




	}
	


};
