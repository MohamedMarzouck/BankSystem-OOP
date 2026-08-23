
#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsFindCurrencyScreen : protected clsScreen
{
private:
	static bool _FindCurrencyByCurrencyCode(clsCurrency& C)
	{
		short FailedAttempt = 3;
		string CountryCode;
		while (true)
		{
			CountryCode = clsInputValidate::ReadString("\nEnter a currency code:   ");
			C = clsCurrency::FindByCode(CountryCode);
			if (!C.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nCurrency with [" << CountryCode << "] does not exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

	static bool _FindCurrencyByCountry(clsCurrency& C)
	{
		short FailedAttempt = 3;
		string Country;
		while (true)
		{
			Country = clsInputValidate::ReadString("\nEnter a country:   ");
			C = clsCurrency::FindByCountry(Country);
			if (!C.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nCurrency with [" << Country << "] does not exist, you have only [" << FailedAttempt << "] trials left.";
		}

		return false;
	}

	static void _PrintCurrencyLine(const clsCurrency& C)
	{
		cout << "\n\t\t Currency Card:";
		cout << "\n\t------------------------------------";
		cout << "\n\t County       :   " << C.GetCountry();
		cout << "\n\t Currency Code:   " << C.GetCurrencyCode();
		cout << "\n\t Currency Name:   " << C.GetCurrencyName();
		cout << "\n\t Rate         :   " << C.GetRate();
		cout << "\n\t------------------------------------";
	}



public:

	static void FindCurrencyScreen()
	{
		_ScreenHeader("\t Find Currency Screen");

		short Answer = 0;
		clsCurrency Curr;

		cout << "\nFind By: [1] Code Or [2] Country:   ";
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (Answer == 1)
		{
			if (_FindCurrencyByCurrencyCode(Curr))
				_PrintCurrencyLine(Curr);

			else
				cout << "\n\t Currency doesn't exist!\n";
		}
		else if (Answer == 2)
		{
			if (_FindCurrencyByCountry(Curr))
				_PrintCurrencyLine(Curr);

			else
				cout << "\n\t Currency doesn't exist!\n";
		}

	}


};

