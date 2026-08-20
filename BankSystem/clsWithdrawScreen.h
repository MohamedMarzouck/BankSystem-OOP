
#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


class clsWithdrawScreen : protected clsScreen
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
	static void WithdrawScreen()
	{
		_ScreenHeader("\t Withdraw Screen");

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
		Amount = clsInputValidate::ReadDblNumber("\nEnter the Withdraw Amount:   ");
		if (Amount <= 0 || Amount > Client.AccBalance || Amount % 20 != 0)
		{
			cout << "\nWithdraw Failed!\n";
			return;
		}

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Transaction [Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Withdraw(Amount);
			cout << "\nDone Successfully. New balance is: " << Client.AccBalance << endl;
		}
		else
			cout << "\nWithdraw Operation Cancelled.\n";
	}
};

