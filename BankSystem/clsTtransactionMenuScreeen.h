
#pragma once
#include<iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTtransferBalanceScreen.h"
#include "clsTransferLogScreen.h"


class clsTtransactionMenuScreeen : protected clsScreen
{
private:
    enum enTrasactionMenuOption
    {
        eDeposit = 1,
        eWithdraw,
        eTotalBalance,
        eTransfer,
        eTransferLog,
        eMainMenu
    };
    static enTrasactionMenuOption _ReadTransactionMenuOption()
    {
        short Option = clsInputValidate::ReadShortNumberBetween(1, 6);
        return (enTrasactionMenuOption)Option;
    }
    static void _GoBackToTransactionMenu()
    {
        cout << "\nEnter any key to go to transaction menu...\n";
        system("pause>0");
    }

    static void PerformTransactionMenuOption(enTrasactionMenuOption Option)
    {
        switch (Option)
        {
        case enTrasactionMenuOption::eDeposit:
            _DepositScreen();
            _GoBackToTransactionMenu();
            break;

        case enTrasactionMenuOption::eWithdraw:
            _WithdrawScreen();
            _GoBackToTransactionMenu();
            break;

        case enTrasactionMenuOption::eTotalBalance:
            _TotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;

        case enTrasactionMenuOption::eTransfer:
            _TtransferBalanceScreen();
            _GoBackToTransactionMenu();
            break;

        case enTrasactionMenuOption::eTransferLog:
            _TransferLogScreen();
            _GoBackToTransactionMenu();
            break;

        case enTrasactionMenuOption::eMainMenu:
            break;
        }
    }

    static void _DepositScreen()
    {
        clsDepositScreen::DepositScreen();
    }
    static void _WithdrawScreen()
    {
        clsWithdrawScreen::WithdrawScreen();
    }
    static void _TotalBalanceScreen()
    {
        clsTotalBalanceScreen::TotalBalanceScreen();
    }
    static void _TtransferBalanceScreen()
    {
        clsTtransferBalanceScreen::TransferScreen();
    }
    static void _TransferLogScreen()
    {
        clsTransferLogScreen::ListTransferLogsScreen();
    }


public:
    static void TransactionMenuScreen()
    {
        enTrasactionMenuOption Option;

        do
        {
            _ScreenHeader("\t Transaction Menu Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t Transaction Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposite.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] TotalBalance.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] TtransferLog Screen.\n";
            cout << setw(37) << left << "" << "\t[6] MainMenuScreen.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            Option = _ReadTransactionMenuOption();
            PerformTransactionMenuOption(Option);

        } while (Option != enTrasactionMenuOption::eMainMenu);
    }
};

