
#pragma once
#include<iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"


class clsCurrencyListScreen : protected clsScreen
{
	static void _PrintCurrencyLine(const clsCurrency& C)
	{
		cout << "\t| " << setw(25) << left << C.GetCountry();
		cout << "\t| " << setw(37) << left << C.GetCurrencyName();
		cout << "\t| " << setw(15) << left << C.GetCurrencyCode();
		cout << "\t| " << setw(15) << left << C.GetRate() << " |\n";
	}

public:
	static void CurrencyListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::ListCurrencies();
		string Subtitle = "Number Of Currencies  = " + to_string(vCurrencies.size()) + " Client(s)";
		_ScreenHeader("\t Currency List Screen", Subtitle);

		cout << "\t---------------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t| " << setw(25) << left << "Country";
		cout << "\t| " << setw(37) << left << "Currency Name";
		cout << "\t| " << setw(15) << left << "Currency Code";
		cout << "\t| " << setw(15) << left << "Rate" << " |\n";
		cout << "\t---------------------------------------------------------------------------------------------------------------------------\n";
		if (vCurrencies.empty())
			cout << "\t\t\t\t\tThe Clients System Is Empty!\n";
		else
			for (const clsCurrency& C : vCurrencies)
				_PrintCurrencyLine(C);

		cout << "\t---------------------------------------------------------------------------------------------------------------------------\n";

	}
};

