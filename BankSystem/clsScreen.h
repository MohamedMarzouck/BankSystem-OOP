
#pragma once

using namespace std;
#include "clsUser.h"
#include "clsGlobal.h"
#include "clsDate.h"

class clsScreen
{

protected:
    static void _ScreenHeader(const string& Title, const string& SubTitle = "")
    {
        system("cls");

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;

        if (SubTitle != "")
            cout << "\n\t\t\t\t\t  " << SubTitle;

        cout << "\n\t\t\t\t\t______________________________________\n";

        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate: " << clsDate::GetSystemDate().DateToString() << endl << endl;

    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermissions(Permission))
        {
            cout << "\t\t\t\t\t______________________________________\n";
            cout << "\t\t\t\t\t  Access Denied! Contact your Admin.\n";
            cout << "\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;
    }
};

