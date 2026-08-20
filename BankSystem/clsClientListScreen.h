
#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"


class clsClientListScreen : protected clsScreen
{

	static void _PrintClientLine(const clsBankClient& Client)
	{
		cout << "| " << setw(11) << left << Client.AccNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(30) << left << Client.Name;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(15) << left << Client.Phone;
		cout << "| " << setw(30) << left << Client.Address;
		cout << "| " << setw(12) << left << Client.AccBalance << " |\n";
	}


public:
	static void ClientListScreen()
	{
		vector<clsBankClient> vClients = clsBankClient::ListClients();
		string Subtitle = "\t   Number Of Clients = " + to_string(vClients.size()) + " Client(s)";
		_ScreenHeader("\t   Clients Screen", Subtitle);

		cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << setw(11) << left << "Acc Number";
		cout << "| " << setw(10) << left << "PinCode";
		cout << "| " << setw(30) << left << "Full Name";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << setw(30) << left << "Address";
		cout << "| " << setw(12) << left << "Acc Balance" << " |\n";
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";

		if (vClients.empty())
			cout << "\t\t\tThe Clients System Is Empty!\n";
		else
		{
			for (const clsBankClient& C : vClients)
				_PrintClientLine(C);
		}
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
};

