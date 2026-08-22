
#pragma once
#include "clsInputValidate.h"
#include"clsUser.h"
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
{
	static bool _FindUserByUsername(clsUser& User)
	{
		short FailedAttempt = 3;
		string UName;
		while (true)
		{
			UName = clsInputValidate::ReadString("\nEnter a username:   ");
			User = clsUser::Find(UName);
			if (!User.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\User with [" << UName << "] does not exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

public:
	static void DeleteUserScreen()
	{
		clsScreen::_ScreenHeader("\n\t Delete User Screen");

		clsUser User;
		if (!_FindUserByUsername(User))
		{
			cout << "\nYou have entered an invalid username 3 times, returning to Main Menu...\n";
			return;
		}

		User.Print();

		char Answer = 'N';
		cout << "\nAre you sure you want to delete this user?   ";
		cin >> Answer;

		if (toupper(Answer) != 'Y')
		{
			cout << "\nThe operation cancelled!\n";
			return;
		}

		User.deleteUser();
		cout << "\nThe user delete successfully.\n";
		User.Print();
	}
};

