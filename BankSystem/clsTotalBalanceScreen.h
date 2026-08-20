
#pragma once
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsBankClient.h"

using namespace std;


class clsTotalBalanceScreen : protected clsScreen
{
	static double _GetTotalBalance(const vector<clsBankClient>& vClients)
	{
		double TotalBalance = 0;
		for (const clsBankClient& C : vClients)
			TotalBalance += C.AccBalance;

		return TotalBalance;
	}


public:
	static void TotalBalanceScreen()
	{

		vector<clsBankClient> vClients = clsBankClient::ListClients();
		string Subtitle = "Number Of Clients = " + to_string(vClients.size()) + " Client(s)";

		_ScreenHeader("\t Total Balance Screen", Subtitle);

		
		cout << "\n\t---------------------------------------------------------------------------------------------\n";
		cout << "\t| " << setw(15) << left << "Acc Number";
		cout << "\t| " << setw(40) << left << "Client Name";
		cout << "\t| " << setw(17) << left << "Account Balance" << " |\n";
		cout << "\t---------------------------------------------------------------------------------------------\n";

		if (vClients.empty())
			cout << "\t\t\t\t\tThe Clients System Is Empty!\n";
		else
		{
			for (const clsBankClient& C : vClients)
			{
				cout << "\t| " << setw(15) << left << C.AccNumber;
				cout << "\t| " << setw(40) << left << C.Name;
				cout << "\t| " << setw(17) << left << C.AccBalance << " |\n";
			}
		}
		cout << "\t---------------------------------------------------------------------------------------------\n";
		float TotalBalance = _GetTotalBalance(vClients);
		cout << "\t\t\t\t Total Balance:\t\t\t\t\t  " << TotalBalance << "\n";
		cout << "\t\t\t\t " << clsUtil::NumberToText(TotalBalance);
		cout << "\n\t---------------------------------------------------------------------------------------------\n";
	}
};

