
#pragma once
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsScreen.h"

class clsFindUserScreen : protected clsScreen
{
	static bool _FindUserByUserName(clsUser& User)
	{
		short FailedAttempt = 3;
		string uName;
		while (true)
		{
			uName = clsInputValidate::ReadString("\nEnter a username:   ");
			User = clsUser::Find(uName);
			if (!User.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\User with [" << uName << "] does not exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

public:
	static void FindUserScreen()
	{
		clsScreen::_ScreenHeader("\n\t Find User Screen");

		clsUser User;
		if (_FindUserByUserName(User))
			User.Print();
		else
			cout << "\nYou have entered an invalid username 3 times, returning to Main Menu...\n";
	}
};

