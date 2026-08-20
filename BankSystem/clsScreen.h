
#pragma once
#include<iostream>
using namespace std;

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
    }
};

