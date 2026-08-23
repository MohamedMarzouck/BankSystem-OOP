
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsTransferCurrencyScreen.h"


class clsCurrencyExchangeMenuScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOption { ListCurrencies  = 1, FindCurrency, UpdateRate, CurrencyCalculator, MainMenu};
	static enCurrencyExchangeOption _ReadCurrencyExchangeOption()
	{
		short Option = clsInputValidate::ReadShortNumberBetween(1, 5);
		return enCurrencyExchangeOption(Option);
	}
	static void _GoBackToCurrencyExchange()
	{
		cout << "\n Enter any key to go to the currency menu...";
		system("pause>0");
	}
	static void _PerformCurrencyExchangeOption(enCurrencyExchangeOption Option)
	{
		switch (Option)
		{
		case enCurrencyExchangeOption::ListCurrencies:
			_CurrencyListScreen();
			_GoBackToCurrencyExchange();
			break;
		case enCurrencyExchangeOption::FindCurrency:
			_FindCurrencyScreen();
			_GoBackToCurrencyExchange();
			break;
		case enCurrencyExchangeOption::UpdateRate:
			_UpdateCurrencyRate();
			_GoBackToCurrencyExchange();
			break;
		case enCurrencyExchangeOption::CurrencyCalculator:
			_TransferCurrencyScreen();
			_GoBackToCurrencyExchange();
			break;
		case enCurrencyExchangeOption::MainMenu:
			break;
		}
	}
	static void _CurrencyListScreen()
	{
		clsCurrencyListScreen::CurrencyListScreen();
	}
	static void _FindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrencyScreen();
	}
	static void _UpdateCurrencyRate()
	{
		clsUpdateCurrencyRate::UpdateCurrencyRate();
	}
	static void _TransferCurrencyScreen()
	{
		clsTransferCurrencyScreen::TransferCurrencyScreen();
	}




public:

	static void CurrencyExchangeScreen()
	{
		enCurrencyExchangeOption Option;
		do
		{
			_ScreenHeader("\t Currency Exchange Screen");
			_CheckAccessRights(clsUser::enPermissions::pCurrencyExchange);

			cout << "\n\t\t\t\t\t ==============================================================";
			cout << "\n\t\t\t\t\t\t Currency Exchange Menu";
			cout << "\n\t\t\t\t\t ==============================================================";
			cout << "\n\t\t\t\t\t   [1] List Currencies.";
			cout << "\n\t\t\t\t\t   [2] Find Currency.";
			cout << "\n\t\t\t\t\t   [3] Update Rate.";
			cout << "\n\t\t\t\t\t   [4] Currency Calculator.";
			cout << "\n\t\t\t\t\t   [5] Main Menu.";
			cout << "\n\t\t\t\t\t ==============================================================";

			Option = _ReadCurrencyExchangeOption();
			_PerformCurrencyExchangeOption(Option);

		} while (Option != enCurrencyExchangeOption::MainMenu);
	}
};

