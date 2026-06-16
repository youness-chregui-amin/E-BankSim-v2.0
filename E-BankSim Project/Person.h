#pragma once
#include <iostream>
#include "InterfaceCommunicationLib.h"
using namespace std;

class clsPerson : public clsInterfaceCommunication
{
private:

	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;

public:

	clsPerson(string Firstname, string Lastname, string Email, string Phone)
	{

		_FirstName = Firstname;
		_LastName = Lastname;
		_Phone = Phone;
		_Email = Email;

	}

	void SetFirstname(string firstname)
	{

		_FirstName = firstname;

	}
	string GetFirstname()
	{

		return _FirstName;
	}
	__declspec(property(get = GetFirstname, put = SetFirstname)) string FirstName;

	void SetLastname(string lastname)
	{
		_LastName = lastname;


	}
	string GetLastname()
	{
		return _LastName;

	}

	__declspec(property(get = GetLastname, put = SetLastname)) string LastName;

	void SetEmail(string Email)
	{

		_Email = Email;

	}
	string GetEmail()
	{

		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	void SetPhone(string Phone)
	{

		_Phone = Phone;

	}
	string GetPhone()
	{

		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;

	}
	void SendEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{


	}


};


