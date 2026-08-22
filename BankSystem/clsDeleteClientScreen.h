
#pragma once
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsDeleteClientScreen : protected clsScreen
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
	static void DeleteClientScreen()
	{
		_ScreenHeader("\n\t Update Client Screen");
		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient)) return;

		clsBankClient Client;
		if (!_FindClientByAccountNumber(Client))
		{
			cout << "\nYou have entered an invalid account number 3 times, returning to Main Menu...\n";
			return;
		}

		Client.Print();

		char Answer = 'N';
		cout << "\nAre you sure you want to remove this client[Y, N]?   ";
		cin >> Answer;

		if (toupper(Answer) != 'Y')
		{
			cout << "\nThe operation cancelled!\n";
			return;
		}

		Client.deleteClient();
		cout << "\nThe client deleted successfully.\n";
		Client.Print();
	}
};

