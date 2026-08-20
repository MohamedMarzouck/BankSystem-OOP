
#pragma once
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
{
	static bool _FindClientByAccountNumber(clsBankClient& Client)
	{
		short FailedAttempt = 3;
		string AccountNumber;
		while (true)
		{
			AccountNumber = clsInputValidate::ReadString("\nEnter an account number:   ");
			Client = clsBankClient::Find(AccountNumber);
			if (!Client.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nClient with [" << AccountNumber << "] does not exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

public:
	static void FindClientScreen()
	{
		clsScreen::_ScreenHeader("\n\t Find Client Screen");

		clsBankClient Client;
		if (_FindClientByAccountNumber(Client))
			Client.Print();
		else
			cout << "\nYou have entered an invalid account number 3 times, returning to Main Menu...\n";
	}
};

