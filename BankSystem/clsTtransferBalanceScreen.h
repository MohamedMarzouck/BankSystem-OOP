
#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsTransferLog.h"
#include "clsDate.h"


class clsTtransferBalanceScreen : protected clsScreen
{
	static bool _FindClientByAccountNumber(clsBankClient& Client)
	{
		short FailedAttempt = 3;
		string AccountNumber;

		while (true)
		{
			AccountNumber = clsInputValidate::ReadString();
			Client = clsBankClient::Find(AccountNumber);
			if (!Client.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nClient with [" << AccountNumber << "] does not exist, you have only [" << FailedAttempt << "] trials left!, enter again:   ";
		}

		return false;
	}

	static void _PrintClientCard(const clsBankClient& Client)
	{
		cout << "\n-----------------------";
		cout << "\nAcc Number :   " << Client.AccNumber;
		cout << "\nName       :   " << Client.Name;
		cout << "\nAcc Balance:   " << Client.AccBalance;
		cout << "\n-----------------------\n";
	}

public:
	static void TransferScreen()
	{
		_ScreenHeader("\t\t Transfer Balance Screen");

		clsBankClient ClientFrom;
		clsBankClient ClientTo;
		
		cout << "\nEnter the account number transfer from:   ";
		if (!_FindClientByAccountNumber(ClientFrom))
		{
			cout << "\nAccountt number with [" << ClientFrom.AccNumber << "] is wrong.\n";
			return;
		}
		_PrintClientCard(ClientFrom);

		cout << "\nEnter the account number transfer to:   ";
		if (!_FindClientByAccountNumber(ClientTo))
		{
			cout << "\nAccountt number is wrong with [" << ClientTo.AccNumber << "] is wrong.\n";
			return;
		}
		_PrintClientCard(ClientTo);

		if (ClientFrom.AccNumber == ClientTo.AccNumber)
		{
			cout << "\nYou cannot transfer to the same account number\n";
			return;
		}


		double Amount = 0;
		Amount = clsInputValidate::ReadDblNumber("\nEnter the transfer Amount:   ");
		if (Amount <= 0 || Amount > ClientFrom.AccBalance)
		{
			cout << "\nThe amount is invalid!";
			return;
		}

		char Answer = 'N';
		cout << "\nAre You Sure You Want To Perform This Transaction [Y/N]? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			ClientFrom.Withdraw(Amount);
			ClientTo.Deposit(Amount);

			cout << "\nDone Successfully.";
			_PrintClientCard(ClientFrom);
			_PrintClientCard(ClientTo);

			
			clsTransferLog::RegisterTransferLog(ClientFrom, ClientTo, Amount);
		}
		else
		{
			cout << "\ntransfer Operation Cancelled.\n";
		}
	}
};

