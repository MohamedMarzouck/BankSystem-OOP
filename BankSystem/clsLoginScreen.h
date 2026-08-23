
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsGlobal.h"
#include "clsMainMenuScreen.h"
#include "clsLoginRegister.h"

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
			clsLoginRegister::RegisterLogin(CurrentUser.UserName, CurrentUser.Password, CurrentUser.Permissions);
			clsMainMenuScreen::MainMenuScreen();
		}
	}
};




