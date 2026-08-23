
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

const string LoginRegisterFileName = "LoginRegisterFile.txt";

class clsLoginRegister
{
private:
	string _DateTime;
	string _UserName;
	string _Password;
	int _Permissions;

	static string _ConvertLoginRegisterObjectToLine(const clsLoginRegister& Record, const string& Seperator = "#||#")
	{
		string Line = "";
		Line += Record.DateTime + Seperator;
		Line += Record.UserName + Seperator;
		// Line += Record.Password + Seperator;
		Line += clsUtil::EncryptText(Record.Password, 3) + Seperator;
		Line += to_string(Record.Permissions);
		return Line;
	}

	static clsLoginRegister _ConvertLineToLoginRegisterObject(const string& Line, const string& Seperator = "#||#")
	{
		vector<string> vData = clsString::_Split(Line, Seperator);

		if (vData.size() < 4)
			return clsLoginRegister("", "", "", 0);

		return clsLoginRegister(vData[0], vData[1], clsUtil::DecryptText(vData[2], 3), stoi(vData[3]));
	}

	static void _AddDataLineToFile(const string& Line)
	{
		fstream myFile;
		myFile.open(LoginRegisterFileName.c_str(), ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << Line << endl;
			myFile.close();
		}
	}

public:
	clsLoginRegister(string DateTime, string UserName, string Password, int Permissions)
	{
		_DateTime = DateTime;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	string Get_DateTime() const { return _DateTime; } // ReadOnlyProperties;
	string Get_UserName() const { return _UserName; }
	string Get_Password() const { return _Password; }
	int Get_Permissions() const { return _Permissions; }

	__declspec(property(get = Get_DateTime)) string DateTime;
	__declspec(property(get = Get_UserName)) string UserName;
	__declspec(property(get = Get_Password)) string Password;
	__declspec(property(get = Get_Permissions)) int Permissions;


	static void RegisterLogin(string UserName, string Password, int Permissions)
	{
		string DateTime = clsDate::GetSystemDateTimeString(); // *********;
		clsLoginRegister Record(DateTime, UserName, Password, Permissions);

		_AddDataLineToFile(_ConvertLoginRegisterObjectToLine(Record));
	}

	static vector<clsLoginRegister> GetLoginRegisterList()
	{
		vector<clsLoginRegister> vRecords;
		fstream myFile;
		myFile.open(LoginRegisterFileName, ios::in);

		if (myFile.is_open())
		{
			string Line;
			while (getline(myFile, Line))
				if (Line != "")
					vRecords.push_back(_ConvertLineToLoginRegisterObject(Line));

			myFile.close();
		}
		return vRecords;
	}
};