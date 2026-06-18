#include <iostream>
#include "InputValidation.h"
#include "BankClient.h"
#include <iomanip>
#include "UtilLib.h"
#include "MainScreen.h"
#include "LoginScreen.h"

using namespace std;



int main()
{

	
	system("color 0B");

	while (true)
	{
		
		if (!clsLoginScreen::ShowLoginScreen())
		break;

	}
	

	
	return 0;


}

