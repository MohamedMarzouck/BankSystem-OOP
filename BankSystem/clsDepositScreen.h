
#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


class clsDepositScreen : protected clsScreen
{
	static bool _FindClientByAccountNumber(clsBankClient& Client)
	{
		short FailedAttempt = 3;
		string AccountNumber;

		while (true)
		{
			AccountNumber = clsInputValidate::ReadString("\nEnter the account number:   ");
			Client = clsBankClient::Find(AccountNumber);
			if (!Client.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nClient with [" << AccountNumber << "] does not exist, you have only [" << FailedAttempt << "] trials left!";
		}

		return false;
	}


public:
	static void DepositScreen()
	{
		_ScreenHeader("\t\t Deposit Screen");

		clsBankClient Client;
		if (!_FindClientByAccountNumber(Client))
		{
			cout << "\nAccount number with [" << Client.AccNumber << "] is wrong\n";
			return;
		}

		cout << "\nAcc Number :   " << Client.AccNumber;
		cout << "\nName       :   " << Client.Name;
		cout << "\nAcc Balance:   " << Client.AccBalance;

		int Amount = 0;
		Amount = clsInputValidate::ReadDblNumber("\nEnter the deposit Amount:   ");
		if (Amount <= 0 || Amount % 10 != 0)
		{
			cout << "\nThe amount is invalid!";
			return;
		}


		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Transaction [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\nDone Successfully. New balance is: " << Client.AccBalance << endl;
		}
		else
			cout << "\Deposit Operation Cancelled.\n";
	}
};

