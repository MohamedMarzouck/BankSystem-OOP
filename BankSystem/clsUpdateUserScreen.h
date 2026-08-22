
#pragma once
#include "clsInputValidate.h"
#include"clsUser.h"
#include "clsScreen.h"

class clsUpdateUserScreen : protected clsScreen
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

	static void ReadUserInfo(clsUser& User)
	{
		cout << "\n\tEnter User info:";
		User.Password = clsInputValidate::ReadString("\nEnter Password :   ");
		User.Name = clsInputValidate::ReadString("Enter Name   :   ");
		User.Email = clsInputValidate::ReadString("Enter Email   :   ");
		User.Phone = clsInputValidate::ReadString("Enter Phone   :   ");
		User.Address = clsInputValidate::ReadString("Enter Address :   ");
		User.Permissions = clsUser::ReadPermissions();
	}


public:
	static void UpdateUserScreen()
	{
		clsScreen::_ScreenHeader("\n\t Update User Screen");

		clsUser User;
		if (!_FindUserByUsername(User))
		{
			cout << "\nYou have entered an invalid username 3 times, returning to Main Menu...\n";
			return;
		}

		User.Print();

		char Answer = 'N';
		cout << "\nAre you sure you want to update this user?   ";
		cin >> Answer;

		if (toupper(Answer) != 'Y')
		{
			cout << "\nThe operation cancelled!\n";
			return;
		}

		ReadUserInfo(User);
		clsUser::enSaveResult SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceeded:
			cout << "\nThe user updated successfully.\n";
			User.Print();
			break;

		case clsUser::enSaveResult::svFailedEmptyMode:
			cout << "\nThe user is Empty!\n";
			break;

		default:
			cout << "\nError, the user is empty!\n";
			break;
		}
	}
};

