
#pragma once
#include "clsInputValidate.h"
#include"clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsUpdateClientScreen : protected clsScreen
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

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n\tEnter client info:";
		Client.PinCode = clsInputValidate::ReadString("\nEnter pincode :   ");
		Client.Name = clsInputValidate::ReadString("Enter Name   :   ");
		Client.Email = clsInputValidate::ReadString("Enter Email   :   ");
		Client.Phone = clsInputValidate::ReadString("Enter Phone   :   ");
		Client.Address = clsInputValidate::ReadString("Enter Address :   ");
		Client.AccBalance = clsInputValidate::ReadDblNumber("Enter Acc Balance:   ");
	}


public:
	static void UpdateClientScreen()
	{
		_ScreenHeader("\n\t Update Client Screen");
		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClient)) return;

		clsBankClient Client;
		if (!_FindClientByAccountNumber(Client))
		{
			cout << "\nYou have entered an invalid account number 3 times, returning to Main Menu...\n";
			return;
		}

		char Answer = 'N';
		cout << "\nAre you sure you want to update this client?   ";
		cin >> Answer;

		if (toupper(Answer) != 'Y')
		{
			cout << "\nThe operattion cancelled!\n";
			return;
		}

		ReadClientInfo(Client);
		clsBankClient::enSaveResult SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "\nThe client updated successfully.\n";
			Client.Print();
			break;

		case clsBankClient::enSaveResult::svFailedEmptyMode:
			cout << "\nThe client is Empty!\n";
			break;

		default:
			cout << "\nError, The client is empty!\n";
			break;
		}
	}
};

