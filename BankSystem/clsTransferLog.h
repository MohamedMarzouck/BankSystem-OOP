
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
#include "clsString.h"
const string TransferLogFileName = "TransferLogFile.txt";

class clsTransferLog
{
private:
	string _AccNumberFrom;
	string _AccNumberTo;
	string _NameFrom;
	string _NameTo;
	string _DateTime;
	double _BalanceFromBefor;
	double _BalanceFromAfter;
	double _BalanceToBefor;
	double _BalanceToAfter;
	int  _Amount;


	static string _ConvertTransferLogObjectToLine(const clsTransferLog& TransferLog, const string& Seperator = "#||#")
	{
		string ClientData = "";
		ClientData += TransferLog.AccNumberFrom + Seperator;
		ClientData += TransferLog.NameFrom + Seperator;
		ClientData += to_string(TransferLog.BalanceFromBefor) + Seperator;
		ClientData += to_string(TransferLog.BalanceFromAfter) + Seperator;
		ClientData += to_string(TransferLog.Amount) + Seperator;
		ClientData += TransferLog.AccNumberTo + Seperator;
		ClientData += TransferLog.NameTo + Seperator;
		ClientData += to_string(TransferLog.BalanceToBefor) + Seperator;
		ClientData += to_string(TransferLog.BalanceToAfter) + Seperator;
		ClientData += TransferLog.DateTime + Seperator;


		return ClientData;
	}
	static void _AddDataLineToFile(const string& FileName, const string& Line)
	{
		fstream myFile;
		myFile.open(FileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << Line << endl;
			myFile.close();
		}
	}
	static clsTransferLog _ConvertLineDataToTransferLogObject(string Line)
	{
		vector<string> vTransferLog = clsString::_Split(Line, "#||#");

		if (vTransferLog.size() < 10)
			return _GetEmptyTransferLogObject();

		return clsTransferLog
		(
			vTransferLog[0],
			vTransferLog[1],
			stod(vTransferLog[2]),
			stod(vTransferLog[3]),
			stod(vTransferLog[4]),
			vTransferLog[5],
			vTransferLog[6],
			stod(vTransferLog[7]),
			stod(vTransferLog[8]),
			vTransferLog[9]
		);
	}
	static clsTransferLog _GetEmptyTransferLogObject()
	{
		return clsTransferLog();
	}
	static vector<clsTransferLog> _LoadTransferLogsObjectFromFile(const string& FileName)
	{
		vector<clsTransferLog> vTransferLogs;
		fstream myFile;
		myFile.open(FileName, ios::in);

		if (myFile.is_open())
		{
			string Line;
			clsTransferLog TransferLog;
			while (getline(myFile, Line))
			{

				TransferLog = _ConvertLineDataToTransferLogObject(Line);
				vTransferLogs.push_back(TransferLog);
			}
			myFile.close();
		}
		return vTransferLogs;
	}
	static void _SaveClientsObjectInFile(const string& FileName, vector<clsTransferLog>& TransferLogs)
	{
		fstream myFile;
		myFile.open(FileName, ios::out);

		if (myFile.is_open())
		{
			for (clsTransferLog& Log : TransferLogs)
				myFile << _ConvertTransferLogObjectToLine(Log) << endl;

			myFile.close();
		}
	}
	static string _GetTransferLogFile()
	{
		return TransferLogFileName;
	}




public:
	clsTransferLog() : _AccNumberFrom(""), _NameFrom(""), _BalanceFromBefor(0), _BalanceFromAfter(0), _Amount(0), _AccNumberTo(""), _NameTo(""), _BalanceToBefor(0), _BalanceToAfter(0), _DateTime("")
	{
	}
	clsTransferLog(string AccNumberFrom, string NameFrom, double BalanceFromBefor, double BalanceFromAfter, int Amount, string AccNumberTo, string NameTo,double BalanceToBefor, double BalanceToAfter, string DateTime)
		: _AccNumberFrom(AccNumberFrom), _NameFrom(NameFrom), _BalanceFromBefor(BalanceFromBefor), _BalanceFromAfter(BalanceFromAfter), _Amount(Amount),
		_AccNumberTo(AccNumberTo), _NameTo(NameTo), _BalanceToBefor(BalanceToBefor), _BalanceToAfter(BalanceToAfter),_DateTime(DateTime)
		 
	{ 
	}

	void Set_AccNumberFrom(string AccNumberFrom)
	{
		_AccNumberFrom = AccNumberFrom;
	}
	void Set_AccNumberTo(string AccNumberTo)
	{
		_AccNumberTo = AccNumberTo;
	}
	void Set_NameFrom(string NameFrom)
	{
		_NameFrom = NameFrom;
	}
	void Set_NameTo(string NameTo)
	{
		_NameTo = NameTo;
	}
	void Set_DateTime(string DateTime)
	{
		_DateTime = DateTime;
	}

	void Set_BalanceFromBefor(double BalanceFromBefor)
	{
		_BalanceFromBefor = BalanceFromBefor;
	}
	void Set_BalanceFromAfter(double BalanceFromAfter)
	{
		_BalanceFromAfter = BalanceFromAfter;
	}
	void Set_BalanceToBefor(double BalanceToBefor)
	{
		_BalanceToBefor = BalanceToBefor;
	}
	void Set_BalanceToAfter(double BalanceToAfter)
	{
		_BalanceToAfter = BalanceToAfter;
	}
	void Set_Amount(int Amount)
	{
		_Amount = Amount;
	}
	string Get_AccNumberFrom()const
	{
		return _AccNumberFrom;
	}
	string Get_AccNumberTo()const
	{
		return _AccNumberTo;
	}
	string Get_NameFrom()const
	{
		return _NameFrom;
	}
	string Get_NameTo()const
	{
		return _NameTo;
	}
	string Get_DateTime()const
	{
		return _DateTime;
	}

	double Get_BalanceFromBefor()const
	{
		return _BalanceFromBefor;
	}
	double Get_BalanceFromAfter()const
	{
		return _BalanceFromAfter;
	}
	double Get_BalanceToBefor()const
	{
		return _BalanceToBefor;
	}
	double Get_BalanceToAfter()const
	{
		return _BalanceToAfter;
	}
	int Get_Amount()const
	{
		return _Amount;
	}
	__declspec(property(get = Get_AccNumberFrom, put = Set_AccNumberFrom)) string AccNumberFrom;
	__declspec(property(get = Get_AccNumberTo, put = Set_AccNumberTo)) string AccNumberTo;
	__declspec(property(get = Get_NameFrom, put = Set_NameFrom)) string NameFrom;
	__declspec(property(get = Get_NameTo, put = Set_NameTo)) string NameTo;
	__declspec(property(get = Get_DateTime, put = Set_DateTime)) string DateTime;
	__declspec(property(get = Get_BalanceFromBefor, put = Set_BalanceFromBefor)) double BalanceFromBefor;
	__declspec(property(get = Get_BalanceFromAfter, put = Set_BalanceFromAfter)) double BalanceFromAfter;
	__declspec(property(get = Get_BalanceToBefor, put = Set_BalanceToBefor)) double BalanceToBefor;
	__declspec(property(get = Get_BalanceToAfter, put = Set_BalanceToAfter)) double BalanceToAfter;
	__declspec(property(get = Get_Amount, put = Set_Amount)) int Amount;


	static string GetTransferLogFile()
	{
		return _GetTransferLogFile();
	}
	static void AddTransferLogToFile(clsTransferLog& Log)
	{
		_AddDataLineToFile(GetTransferLogFile(), _ConvertTransferLogObjectToLine(Log));
	}
	static vector<clsTransferLog> ListTransferLog()
	{
		vector<clsTransferLog> vLogs = _LoadTransferLogsObjectFromFile(GetTransferLogFile());
		return vLogs;
	}
	static void RegisterTransferLog(const clsBankClient& ClientFrom, const clsBankClient& ClientTo, double Amount)
	{
		clsTransferLog Log;

		Log.AccNumberFrom = ClientFrom.AccNumber;
		Log.NameFrom = ClientFrom.Name;
		Log.BalanceFromAfter = ClientFrom.AccBalance;
		Log.BalanceFromBefor = Log.BalanceFromAfter + Amount;
		Log.Amount = Amount;

		Log.AccNumberTo = ClientTo.AccNumber;
		Log.NameTo = ClientTo.Name;
		Log.BalanceToAfter = ClientTo.AccBalance;
		Log.BalanceToBefor = Log.BalanceToAfter - Amount;
		Log.DateTime = clsDate::GetSystemDateTimeString();

		AddTransferLogToFile(Log);

	}



};

