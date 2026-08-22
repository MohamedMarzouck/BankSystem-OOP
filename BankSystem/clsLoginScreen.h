
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsGlobal.h"
#include "clsMainMenuScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _FindUser()
	{
		short FailedAttempt = 3;
		string uName;
		string Pass;
		
		while (true)
		{
			uName = clsInputValidate::ReadString("\n Enter Username:   ");
			Pass = clsInputValidate::ReadString(" Enter Password:   ");
			CurrentUser = clsUser::Find(uName, Pass);

			if (!CurrentUser.IsEmpty()) return true;
			if (--FailedAttempt == 0) break;

			cout << "\n\nInvalid username \ password!, you have only [" << FailedAttempt << "] trials left!";
		}
		return false;
	}


public:

	static void LoginScreen()
	{
		_ScreenHeader("\t\t Login Screen");

		if (_FindUser())
		{
			CurrentUser.AddRegisterLoginToFile();
			clsMainMenuScreen::MainMenuScreen();
		}
	}
};



//static bool _Login()
//{
//	string UserName;
//	string Password;
//	bool LoginFailed = false;
//	short FailedAttempts = 3;
//
//	do
//	{
//		if (LoginFailed)
//		{
//			FailedAttempts--;
//			cout << "\nInvalid username or password!, you have " << FailedAttempts << " Trial(s) left.\n";
//		}
//
//		if (FailedAttempts == 0)
//		{
//			cout << "\nYou are Locked after 3 failed attempts.\n";
//			return false;
//		}
//
//		UserName = clsInputValidate::ReadString("\nEnter Username:   ");
//		Password = clsInputValidate::ReadString("Enter Password:   ");
//
//		CurrentUser = clsUser::Find(UserName, Password);
//
//		LoginFailed = CurrentUser.IsEmpty();
//
//	} while (LoginFailed);
//
//	return true;
//}



