
#pragma once
#include<iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUser.h"



class clsUserMenuScreen : protected clsScreen
{
private:
    enum enUserMenuOption
    {
        eUserList = 1,
        eAddUer,
        eFindUser,
        eUpdateUser,
        eDeleteUser,
        eMainMenu
    };
    static enUserMenuOption _ReadUserMenuOption()
    {
        short Option = clsInputValidate::ReadShortNumberBetween(1, 6);
        return (enUserMenuOption)Option;
    }
    static void _GoBackToUserMenu()
    {
        cout << "\nEnter any key to go to User menu...\n";
        system("pause>0");
    }

    static void PerformUserMenuOption(enUserMenuOption Option)
    {
        switch (Option)
        {
        case enUserMenuOption::eUserList:
            _UsersListScreen();
            _GoBackToUserMenu();
            break;

        case enUserMenuOption::eAddUer:
            _AddNewUserScreen();
            _GoBackToUserMenu();
            break;

        case enUserMenuOption::eFindUser:
            _clsFindUserScreen();
            _GoBackToUserMenu();
            break;

        case enUserMenuOption::eUpdateUser:
            _UpdateUserScreen();
            _GoBackToUserMenu();
            break;

        case enUserMenuOption::eDeleteUser:
            _DeleteUserScreen();
            _GoBackToUserMenu();
            break;

        case enUserMenuOption::eMainMenu:
            break;
        }
    }

    static void _UsersListScreen()
    {
        clsUsersListScreen::UsersListScreen();
    }
    static void _clsFindUserScreen()
    {
        clsFindUserScreen::FindUserScreen();
    }
    static void _UpdateUserScreen()
    {
        clsUpdateUserScreen::UpdateUserScreen();
    }
    static void _DeleteUserScreen()
    {
        clsDeleteUserScreen::DeleteUserScreen();
    }
    static void _AddNewUserScreen()
    {
        clsAddNewUserScreen::AddNewClientScreen();
    }


public:
    static void UserMenuScreen()
    {
        enUserMenuOption Option;

        do
        {
            _ScreenHeader("\t User Menu Screen");
            if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers)) return;

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t User Management Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add User.\n";
            cout << setw(37) << left << "" << "\t[3] Find User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Delete User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menu Screen.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            Option = _ReadUserMenuOption();
            PerformUserMenuOption(Option);

        } while (Option != enUserMenuOption::eMainMenu);
    }
};

