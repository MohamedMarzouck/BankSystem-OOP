
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


public:
	static void TransferScreen()
	{
		_ScreenHeader("\t\tt Deposit Screen");

		clsBankClient ClientFrom;
		clsBankClient ClientTo;
		
		cout << "\nEnter the account number transfer from:   ";
		if (!_FindClientByAccountNumber(ClientFrom))
		{
			cout << "\nAccountt number with [" << ClientFrom.AccNumber << "] is wrong.\n";
			return;
		}
		cout << "\n-----------------------";
		cout << "\nAcc Number :   " << ClientFrom.AccNumber;
		cout << "\nName       :   " << ClientFrom.Name;
		cout << "\nAcc Balance:   " << ClientFrom.AccBalance;
		cout << "\n-----------------------\n";

		cout << "\nEnter the account number transfer to:   ";
		if (!_FindClientByAccountNumber(ClientTo))
		{
			cout << "\nAccountt number is wrong with [" << ClientTo.AccNumber << "] is wrong.\n";
			return;
		}
		cout << "\n-----------------------";
		cout << "\nAcc Number :   " << ClientTo.AccNumber;
		cout << "\nName       :   " << ClientTo.Name;
		cout << "\nAcc Balance:   " << ClientTo.AccBalance;
		cout << "\n-----------------------\n";

		if (ClientFrom.AccNumber == ClientTo.AccNumber)
		{
			cout << "\nYou cannot transfer to the same account number\n";
			return;
		}


		int Amount = 0;
		Amount = clsInputValidate::ReadDblNumber("\nEnter the transfer Amount:   ");
		if (Amount <= 0 || Amount > ClientFrom.AccBalance || Amount % 20 != 0)
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
			cout << "\n-----------------------";
			cout << "\nAcc Number :   " << ClientFrom.AccNumber;
			cout << "\nName       :   " << ClientFrom.Name;
			cout << "\nAcc Balance:   " << ClientFrom.AccBalance;
			cout << "\n-----------------------";
			cout << "\n-----------------------";
			cout << "\nAcc Number :   " << ClientTo.AccNumber;
			cout << "\nName       :   " << ClientTo.Name;
			cout << "\nAcc Balance:   " << ClientTo.AccBalance;
			cout << "\n-----------------------\n";
		}
		else
		{
			cout << "\Ttransfer Operation Cancelled.\n";
			return;
		}
		//--------------------------------------;
		//--------------------------------------;
		//--------------------------------------;
		clsTransferLog Log;
		Log.AccNumberFrom = ClientFrom.AccNumber;
		Log.NameFrom = ClientFrom.Name;
		Log.BalanceFromAfter = ClientFrom.AccBalance; // ***;
		Log.BalanceFromBefor = Log.BalanceFromAfter + Amount;
		Log.Amount = Amount;

		Log.AccNumberTo = ClientTo.AccNumber;
		Log.NameTo = ClientTo.Name;
		Log.BalanceToAfter = ClientTo.AccBalance; // ***;
		Log.BalanceToBefor = Log.BalanceToAfter - Amount;
		Log.DateTime = clsDate::GetSystemDateTimeString();

		clsTransferLog::AddTransferLogInFile(Log);
		//---------------------------------------;
		//---------------------------------------;
		//---------------------------------------;
	}
};

