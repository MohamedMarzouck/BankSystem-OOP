
#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:
	static bool _ReadUsername(string& uName)
	{
		short FailedAttempt = 3;
		clsUser User;
		while (true)
		{
			uName = clsInputValidate::ReadString("\nEnter a username:   ");
			User = clsUser::Find(uName);

			if (User.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\User with [" << uName << "] already exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

	static void ReadUserInfo(clsUser& User)
	{
		cout << "\n\tEnter User info:\n";
		User.Name = clsInputValidate::ReadString("Enter Name     :   ");
		User.Email = clsInputValidate::ReadString("Enter Email    :   ");
		User.Phone = clsInputValidate::ReadString("Enter Phone    :   ");
		User.Address = clsInputValidate::ReadString("Enter Address  :   ");
		User.Password = clsInputValidate::ReadString("Enter Password :   ");
		User.Permissions = clsUser::ReadPermissions();
	}


public:
	static void AddNewClientScreen()
	{
		clsScreen::_ScreenHeader(" Add New User Screen");

		string uName;
		if (!_ReadUsername(uName))
		{
			cout << "\nYou have entered an invalid username 3 times, returning to Main Menu...\n";
			return;
		}

		clsUser User = clsUser::GetAddNewUserObject(uName);

		ReadUserInfo(User);
		//User.UserName = uName;

		clsUser::enSaveResult SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceeded:
			cout << "\nDone, successfully\n";
			User.Print();
			break;
		case clsUser::enSaveResult::svFailedEmptyMode:
			cout << "\nError, the user is empty!\n";
			break;
		case clsUser::enSaveResult::svFailedUserExists:
			cout << "\nError, tthe user is already exists!\n";
			break;
		}

	}




};

