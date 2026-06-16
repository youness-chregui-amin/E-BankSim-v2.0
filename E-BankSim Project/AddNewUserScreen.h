#pragma once
#include <iostream>
#include "User.h"
#include "ManageUsersLib.h"
#include <iomanip>
#include "Screen.h"
#include "InputValidation.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static void _ReadUserInfo(clsUser &User)
	{
		cout << "Enter Your Firstname > ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Your Lastname > ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Your Email > ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Your Phone > ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Your Password > ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Your Permission > ";
		User.Permissions = _ReadPermissionsToSet();

	}
	static void _PrintUser(clsUser User)
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

	static int _ReadPermissionsToSet()
	{

		int Permission = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer =='Y')
		{


			return -1;
		}
		cout << "\Do you want to give access to : \n";

		cout << "\nShow Client List ? y/n > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{


			Permission += clsUser::enPermission::pListClients;


		}
		cout << "\nAdd New Cleint? y/n? > ";
		cin >> Answer;

		if (Answer =='y' || Answer =='Y')
		{

			Permission += clsUser::enPermission::pAddNewClient;

		}
		cout << "\nDelete Client? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pDeleteClient;

		}
		cout << "\nUpdate Client? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pUpdateClients;

		}
		cout << "\nFind Client? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pFindClient;

		}
		cout << "\nTransactions? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pTranactions;

		}
		cout << "\nManage Users? y/n? > ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pManageUsers;

		}
		cout << "\nShow Login Register? y/n? > ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			Permission += clsUser::enPermission::pLoginRegister;

		}


		return Permission;

	}


public:

	static void ShowAddNewUserScreen()
	{


		_DrawScreenHeader("\t Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName > ";

		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{

			cout << "\nUserName Is Already Used, choose another one > ";
			UserName = clsInputValidate::ReadString();


		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveresult SaveResult;

		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		    case clsUser::enSaveresult::svSucceeded:
			{

				cout << "\nUser Added Successfully :-)\n";
				_PrintUser(NewUser);
				break;
			}
			case clsUser::enSaveresult::svFaildEmptyObject:
			{

				cout << "\nError User was not saved because it's Empty";
				break;


			}
			case clsUser::enSaveresult::svFaildUserExists:
			{

				cout << "\nError User was not saved because UserName is used!\n";
				break;

			}

		}



	}


	

};
