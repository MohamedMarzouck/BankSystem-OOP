
#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"


class clsTransferCurrencyScreen : protected clsScreen
{
	static bool _FindCurrencyByCurrencyCode(clsCurrency& C)
	{
		short FailedAttempt = 3;
		string CurrencyCode;
		while (true)
		{
			CurrencyCode = clsInputValidate::ReadString();
			C = clsCurrency::FindByCode(CurrencyCode);
			if (!C.IsEmpty()) return true;

			if (--FailedAttempt == 0) break;

			cout << "\nCurrency with [" << CurrencyCode << "] does not exist, you have only [" << FailedAttempt << "] trials left, enter again:   ";
		}

		return false;
	}
	static void _PrintCurrencyLine(const clsCurrency& C)
	{
		cout << "\n\t\t Convert From:";
		cout << "\n\t------------------------------------";
		cout << "\n\t Country      :   " << C.GetCountry();
		cout << "\n\t Currency Code:   " << C.GetCurrencyCode();
		cout << "\n\t Currency Name:   " << C.GetCurrencyName();
		cout << "\n\t Rate(1$)     :   " << C.GetRate();
		cout << "\n\t------------------------------------";
	}
	static double _ConvertToUSD(const clsCurrency& Currency, double Amount)
	{
		return Amount / Currency.GetRate();
	}

	static double _ConvertFromUSD(const clsCurrency& Currency, double AmountInUSD)
	{
		return AmountInUSD * Currency.GetRate();
	}

public:

	static void TransferCurrencyScreen()
	{
		char Answer = 'n';
		do
		{
			_ScreenHeader("\t Transfer Currency Screen");

			clsCurrency CurrFrom;
			clsCurrency CurrTo;
			cout << "\nEnter a currency code from:   ";
			if (!_FindCurrencyByCurrencyCode(CurrFrom))
			{
				cout << "\nThe currency code doesn't exist!";
				return;
			}
			cout << "\n\tFrom Currency:";
			_PrintCurrencyLine(CurrFrom);


			cout << "\nEnter a currency code to:   ";
			if (!_FindCurrencyByCurrencyCode(CurrTo))
			{
				cout << "\nThe currency code doesn't exist!";
				return;
			}
			cout << "\n\tTo Currency:";
			_PrintCurrencyLine(CurrTo);

		
			string FromCode = clsString::UpperAllString(CurrFrom.GetCurrencyCode());
			string ToCode = clsString::UpperAllString(CurrTo.GetCurrencyCode());

			double Amount = clsInputValidate::ReadDblNumber("\nEnter amount to exchange:   ");

			double AmountInUSD = _ConvertToUSD(CurrFrom, Amount);
			double ConvertedAmount = _ConvertFromUSD(CurrTo, AmountInUSD);

			cout << "\n\tConversion Details:";
			cout << "\n\t------------------------------------";
			cout << "\n\t" << Amount << " " << FromCode << " = " << ConvertedAmount << " " << ToCode << "\n";
			cout << "\n\t------------------------------------";

			cout << "\nDo you want to perform another conversion? (Y/N):   ";
			cin >> Answer;

		} while (toupper(Answer) == 'Y');
	}
};

