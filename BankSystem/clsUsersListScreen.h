
#pragma once
#include<iostream>
#include<iomanip>
#include "clsUser.h"
#include "clsScreen.h"


class clsUsersListScreen : protected clsScreen
{

	static void _PrintUserLine(const clsUser& User)
	{
		cout << "| " << setw(30) << left << User.Name;
		cout << "| " << setw(30) << left << User.Email;
		cout << "| " << setw(15) << left << User.Phone;
		cout << "| " << setw(30) << left << User.Address;
		cout << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(15) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions << " |\n";
	}


public:
	static void UsersListScreen()
	{
		vector<clsUser> vUsers = clsUser::ListUsers();
		string Subtitle = "\t   Number Of Users = " + to_string(vUsers.size()) + " User(s)";
		_ScreenHeader("\t   Users Screen", Subtitle);

		cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << setw(30) << left << "Name";
		cout << "| " << setw(30) << left << "Email";
		cout << "| " << setw(15) << left << "Phone";
		cout << "| " << setw(30) << left << "Address";
		cout << "| " << setw(15) << left << "UserName";
		cout << "| " << setw(15) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions" << " |\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

		if (vUsers.empty())
			cout << "\t\t\tThe Users System Is Empty!\n";
		else
		{
			for (const clsUser& C : vUsers)
				_PrintUserLine(C);
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
};

