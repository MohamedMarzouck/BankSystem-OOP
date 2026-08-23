
#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRate : protected clsScreen
{

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

	static void _PrintCurrencyLine(const clsCurrency& C)
	{
		cout << "\n\t\t Currency Card:";
		cout << "\n\t------------------------------------";
		cout << "\n\t County       :   " << C.GetCountry();
		cout << "\n\t Currency Code:   " << C.GetCurrencyCode();
		cout << "\n\t Currency Name:   " << C.GetCurrencyName();
		cout << "\n\t Rate(1$)     :   " << C.GetRate();
		cout << "\n\t------------------------------------";
	}

public:
	static void UpdateCurrencyRate()
	{
		clsScreen::_ScreenHeader("\t Update Currency Rate");
		
		clsCurrency Curr;
		if (!_FindCurrencyByCurrencyCode(Curr))
		{
			cout << "\nThe currency code doesn't exist!";
			return;
		}
		
			

		_PrintCurrencyLine(Curr);

		char Answer = 'n';
		cout << "\nAre you sure you wantt to update this currency:   ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			double Rate;

			cout << "\nEnter the new rate:   ";
			cin >> Rate;
			Curr.UpdateRate(Rate);

			cout << "\nThe currency rate updated successfully\n";
			_PrintCurrencyLine(Curr);
		}
		else
			cout << "\nThe operation cancelled!\n";
	}
};

