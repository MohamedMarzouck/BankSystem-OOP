
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsAddNewClient : protected clsScreen
{
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

	static bool ReadAccNumber(string& AccountNumber)
	{
		short FailedAttempt = 3;
		clsBankClient Client;
		while (true)
		{
			AccountNumber = clsInputValidate::ReadString("\nEnter the account number: ");
			Client = clsBankClient::Find(AccountNumber);
			if (Client.IsEmpty())
			{
				// Client.AccNumber = AccountNumber;                             // *******;
				return true;
			}

			if (--FailedAttempt == 0) break;

			cout << "\nClient with [" << AccountNumber << "] already exists, you have only [" << FailedAttempt << "] trials left.";
		}
		return false;
	}

public:
	static void AddNewClientScreen()
	{
		clsScreen::_ScreenHeader("\n\t Add New Client Screen");

		clsBankClient Client;
		string AccountNumber;
		if (!ReadAccNumber(AccountNumber))
		{
			cout << "\nYou have entered an invalid account number 3 times, returning to Main Menu...\n";
			return;
		}

		Client = clsBankClient::GetAddNewClientObject(AccountNumber);                  //**************;
		ReadClientInfo(Client);
		clsBankClient::enSaveResult SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "\nThe client saved successfully.\n";
			Client.Print();
			break;

		case clsBankClient::enSaveResult::svFailedEmptyMode:
			cout << "\nThe client is Empty!\n";
			break;

		case clsBankClient::enSaveResult::svFailedClientExists:
			cout << "\nThe client already exists!\n";
			break;

		default:
			cout << "\nError, The client is empty!\n";
			break;
		}
	}
};

