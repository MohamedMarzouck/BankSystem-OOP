
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"

using namespace std;
const string CurrencyFileName = "CurrencyFile.txt";


class clsCurrency
{
private:

	enum enMode
	{
		EmptyMode,
		UpdateMode
	};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;

	static string _ConvertCurrencyObjectToLine(const clsCurrency& Currency, const string& Seperator = "#//#")
	{
		string CurrencyData = "";
		CurrencyData += Currency._Country + Seperator;
		CurrencyData += Currency._CurrencyCode + Seperator;
		CurrencyData += Currency._CurrencyName + Seperator;
		CurrencyData += to_string(Currency._Rate);

		return CurrencyData;
	}
	static void _AddCurrencyLineTtoFile(const string& FileName, const string& Line)
	{
		fstream myFile;
		myFile.open(FileName, ios::out | ios::app);
		if (myFile.is_open())
		{
			myFile << Line << endl;
			myFile.close();
		}
	}
	static clsCurrency _ConvertLineToCurrencyObject(const string& Line)
	{
		vector<string> vCurrency = clsString::_Split(Line, "#//#");
		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
	}
	static vector< clsCurrency> _LoadCurrencyObjectsFromFile(const string& FileName)
	{
		fstream myFile;
		myFile.open(FileName, ios::in);
		vector< clsCurrency> vCurrency;

		if (myFile.is_open())
		{
			string Line;
			while (getline(myFile, Line))
			{
				if (Line != "")
					vCurrency.push_back(_ConvertLineToCurrencyObject(Line));
			}
			myFile.close();
		}

		return vCurrency;
	}
	static void _SaveCurrencyObjectsInFile(const string& FileName, vector< clsCurrency>& vCurrencies)
	{
		fstream myFile;
		myFile.open(FileName, ios::out);
		if (myFile.is_open())
		{
			for (const clsCurrency& C : vCurrencies)
				myFile << _ConvertCurrencyObjectToLine(C);

			myFile.close();
		}
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = ListCurrencies();
		for (clsCurrency& C : vCurrencies)
			if (C.GetCurrencyCode() == _CurrencyCode)
			{
				C = *this;
				break;
			}

		_SaveCurrencyObjectsInFile(CurrencyFileName, vCurrencies);
	}

public:
	clsCurrency() : _Mode(enMode::EmptyMode), _Country(""), _CurrencyCode(""), _CurrencyName(""), _Rate(0)
	{ }
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, double Rate) : _Mode(Mode), _Country(Country), _CurrencyCode(CurrencyCode), _CurrencyName(CurrencyName), _Rate(Rate)
	{ }

	string GetCountry()const { return _Country; }
	string GetCurrencyCode()const { return _CurrencyCode; }
	string GetCurrencyName()const { return _CurrencyName; }
	double GetRate()const { return _Rate; }
	void UpdateRate(double Rate)
	{
		_Rate = Rate;
		_Update();
	}

	bool IsEmpty()const
	{
		return _Mode == enMode::EmptyMode;
	}
	bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C = FindByCode(CurrencyCode);
		return (!C.IsEmpty());
	}

	static clsCurrency FindByCode(const string& CurrencyCode)
	{
		string SearchCode = clsString::UpperAllString(CurrencyCode);

		fstream myFile;
		myFile.open(CurrencyFileName, ios::in);

		if (myFile.is_open())
		{
			string Line;
			
			while (getline(myFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCurrencyCode()) == SearchCode)
				{
					myFile.close();
					return Currency;
				}
			}
			myFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(const string& Country)
	{
		string SearchCode = clsString::UpperAllString(Country);

		fstream myFile;
		myFile.open(CurrencyFileName, ios::in);

		if (myFile.is_open())
		{
			string Line;

			while (getline(myFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.GetCountry()) == SearchCode)
				{
					myFile.close();
					return Currency;
				}
			}
			myFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static vector<clsCurrency> ListCurrencies()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrencyObjectsFromFile(CurrencyFileName);
		return vCurrencies;
	}

};

