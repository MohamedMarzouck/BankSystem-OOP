
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"


const string UsersFileName = "UsersFile.txt";


class clsUser : public clsPerson
{
private:

	enum enMode
	{
		EmptyMode,
		UpdateMode,
		AddNew
	};

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkUserForDelete = false;

	static string _ConvertUserObjectToLine(const clsUser& User, const string& Seperator = "#||#");
	static void _AddDataLineToFile(const string& FileName, const string& Line);
	static clsUser _ConvertLineDataToUserObject(string Line);
	static vector<clsUser> _LoadUsersObjectFromFile(const string& FileName);
	static void _SaveUsersObjectInFile(const string& FileName, vector<clsUser>& vUsres);
	static clsUser _GetEmptyUserObject();
	static string _GetUserFile();

	
	static short _ReadPermissions();
	void _AddNewUser();
	void _Update();


public:
	clsUser();
	clsUser(enMode Mode, string Name, string Email, string Phone, string Address, string UserName, string Password, short Permissions);


	void SetUserName(string UserName);
	void SetPassword(string Password);
	void SetPermissions(int Permissions);
	string GetUserName()const;
	string GetPassword()const;
	int GetPermissions()const;
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;
	static string GetUserFile();

	static vector<clsUser> ListUsers();
	bool IsEmpty();
	static bool IsUserExist(const string& uName);



	static clsUser Find(const string& uName);
	static clsUser Find(const string& uName, const string& Pass);
	static clsUser GetAddNewUserObject(const string& uName);
	void Print();


	enum enSaveResult
	{
		svSucceeded,
		svFailedEmptyMode,
		svFailedUserExists
	};
	enSaveResult Save();
	void deleteUser();
	static short ReadPermissions();
	enum enPermissions
	{
		pAll = -1,

		pClientsList = 1,
		pAddNewClient = 2,
		pFindClient = 4,
		pUpdateClient = 8,
		pDeleteClient = 16,
		pTransaction = 32,
		pLoginRegister = 64,
		pManageUsers = 128,
		pCurrencyExchange = 256
	};

	bool CheckAccessPermissions(enPermissions Permissions);


};

