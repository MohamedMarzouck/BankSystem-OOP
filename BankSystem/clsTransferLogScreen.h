
#pragma once
#include<iostream>
#include<iomanip>
#include "clsTransferLog.h"
#include "clsScreen.h"


class clsTransferLogScreen : protected clsScreen
{
	static void _PrintClientLine(const clsTransferLog& Log)
	{
		cout << "| " << setw(10) << left << Log.AccNumberFrom;
		cout << "| " << setw(30) << left << Log.NameFrom;
		cout << "| " << setw(12) << left << Log.BalanceFromBefor;
		cout << "| " << setw(12) << left << Log.BalanceFromAfter;
		cout << "| " << setw(10) << left << Log.Amount;
		cout << "| " << setw(10) << left << Log.AccNumberTo;
		cout << "| " << setw(30) << left << Log.NameTo;
		cout << "| " << setw(12) << left << Log.BalanceToBefor;
		cout << "| " << setw(12) << left << Log.BalanceToAfter;
		cout << "| " << setw(20) << left << Log.DateTime << " |\n";
	}


public:
	static void ListTransferLogsScreen()
	{
		vector<clsTransferLog> vLogs = clsTransferLog::ListTransferLog();
		string Subtitle = "Number Of Transfer Logs = " + to_string(vLogs.size()) + " Log(s)";

		_ScreenHeader("\t Transfer Log Screen", Subtitle);

		cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << setw(10) << left << "AccN From";
		cout << "| " << setw(30) << left << "Name From";
		cout << "| " << setw(12) << left << "B.From Befor";
		cout << "| " << setw(12) << left << "B.From After";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(10) << left << "AccN To";
		cout << "| " << setw(30) << left << "Name To";
		cout << "| " << setw(12) << left << "B.To Befor";
		cout << "| " << setw(12) << left << "B.To After";
		cout << "| " << setw(20) << left << "Date Time" << "  |\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		if (vLogs.empty())
			cout << "\t\t\tThe Clients System Is Empty!\n";
		else
		{
			for (const clsTransferLog& Log : vLogs)
				_PrintClientLine(Log);
		}
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
};

