
#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsFindClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClientScreen.h"



using namespace std;

class clsMainMenuScreen : protected clsScreen
{
    enum enMainMenuOption
    {
        eClientList = 1,
        eAddNewClient,
        eFindClient,
        eUpdateClient,
        eDeleteClient,
        eTransactionMenu,
        eManageUser,
        eLogout
    };
    static enMainMenuOption _ReadMainMenuOption()
    {
        short Option = clsInputValidate::ReadShortNumberBetween(1, 8);
        return enMainMenuOption(Option);
    }
    static void _GoBackToMainMenu()
    {
        cout << "\n\nEnter any key to go to main menu...\n";
        system("pause>0");
    }
    static void _PerfromMainMenuOption(enMainMenuOption Option)
    {
        switch (Option)
        {
        case eClientList:
            _ClientListScreen();
            _GoBackToMainMenu();
            break;
        case eAddNewClient:
            _AddNewClientScreen();
            _GoBackToMainMenu();
            break;
        case eFindClient:
            _FindClientScreen();
            _GoBackToMainMenu();
            break;
        case eUpdateClient:
            _UpdateClientScreen();
            _GoBackToMainMenu();
            break;
        case eDeleteClient:
            _DeleteClientScreen();
            _GoBackToMainMenu();
            break;
        case eTransactionMenu:
            break;
        case eManageUser:
            break;
        case eLogout:
            break;
        }
    }

    static void _ClientListScreen()
    {
        clsClientListScreen::ClientListScreen();
    }
    static void _AddNewClientScreen()
    {
        clsAddNewClient::AddNewClientScreen();
    }
    static void _FindClientScreen()
    {
        clsFindClientScreen::FindClientScreen();
    }
    static void _UpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClientScreen();
    }
    static void _DeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClientScreen();
    }

public:
	static void MainMenuScreen()
	{
        enMainMenuOption Option;
        do
        {
            clsScreen::_ScreenHeader("\t\t Main Mune");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Find Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            Option = _ReadMainMenuOption();
            _PerfromMainMenuOption(Option);
        } while (Option != enMainMenuOption::eLogout);
	}
};

