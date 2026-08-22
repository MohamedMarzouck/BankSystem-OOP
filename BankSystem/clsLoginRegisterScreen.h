
#pragma once
#include <iomanip>
#include <fstream>
#include <vector>

#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsLoginRegister.h"

class clsLoginRegisterScreen : protected clsScreen
{
	static void _PrintRecordLine(const clsLoginRegister& Record)
	{ 
		cout << "\t\t\t| " << setw(30) << left << Record.DateTime;
		cout << "| " << setw(10) << left << Record.UserName;
		cout << "| " << setw(10) << left << Record.Password;
		cout << "| " << setw(12) << left << Record.Permissions << " |\n";
	}

public:
	static void LoginRegisterScreen()
	{
		vector<clsLoginRegister> vRecords = clsLoginRegister::GetLoginRegisterList();
		string SubTitle = "\t\t (" + to_string(vRecords.size()) + ") Record(s).";

		_ScreenHeader("\t Login Register Screen", SubTitle);
		if (!_CheckAccessRights(clsUser::enPermissions::pLoginRegister)) return;
		          
		cout << "\n\t\t\t------------------------------------------------------------------------\n";
		cout << "\t\t\t| " << setw(30) << left << "Date \ Time";
		cout << "| " << setw(10) << left << "Username";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions  |";
		cout << "\n\t\t\t------------------------------------------------------------------------\n";

		if (vRecords.empty())
			cout << "\t\t\t\tNo Logins Available In the System!\n";
		else
			for (const auto& Record : vRecords)
				_PrintRecordLine(Record);

		cout << "\n\t\t\t------------------------------------------------------------------------\n";
	}
};

