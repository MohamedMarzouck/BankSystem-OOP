
#pragma once
#include<vector>
#include<fstream>
#include<string>

using namespace std;
#include"clsPerson.h"
#include "clsString.h"
const string ClienttsFileName = "ClientsFile.txt";


class clsBankClient : public clsPerson
{
private:
	string _AccNumber;
	string _PinCode;
	double _AccBalance;
	bool _MarkClientByAccNumber = false;
	enum enMode
	{
		EmptyMode,
		UpdateMode,
		AddNewMode
	};
	enMode _Mode;

	static string _ConvertClientObjectToLine(const clsBankClient& Client, const string& Seperator = "#||#");
	static void _AddDataLineToFile(const string& FileName, const string& Line);
	static clsBankClient _ConvertLineDataToClientObject(string Line);
	static vector<clsBankClient> _LoadClientsObjectFromFile(const string& FileName);
	static void _SaveClientsObjectInFile(const string& FileName, vector<clsBankClient>& vClients);
	static clsBankClient _GetEmptyClientObject();
	static string _GetClientFile();

	void _AddNewClient();
	void _Update();


public:
	clsBankClient();
	clsBankClient(enMode Mode, string AccNumber, string PinCode, string Name, string Email, string Phone, string Address, double AccBalance);
	void SetAccNumber(string AccNumber);
	void SetPinCode(string PinCode);
	void SetAccBalance(double AccBalance);
	string GetAccNumber() const;
	string GetPinCode() const;
	double GetAccBalance() const;
	__declspec(property(get = GetAccNumber, put = SetAccNumber)) string AccNumber;
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	__declspec(property(get = GetAccBalance, put = SetAccBalance)) double AccBalance;

	static string GetClientFile();
	static vector<clsBankClient> ListClients();
	bool IsEmpty();
	static bool IsClientExist(const string& AccountNumber);



	static clsBankClient Find(const string& AccountNumber);
	static bool Find(const string& AccountNumber, const string& pCode);
	static clsBankClient GetAddNewClientObject(const string& AccountNumber);
	void Print();



	enum enSaveResult
	{
		svSucceeded,
		svFailedEmptyMode,
		svFailedClientExists
	};
	enSaveResult Save();
	void deleteClient();

	void Deposit(double Amount);
	void Withdraw(double Amount);


};

