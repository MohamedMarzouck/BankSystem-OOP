
#include "clsInputValidate.h"

bool clsInputValidate::IsNumberBetween(short Number, short From, short To)
{
    return (Number >= From && Number <= To);
}
bool clsInputValidate::IsNumberBetween(int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}
bool clsInputValidate::IsNumberBetween(double Number, int From, int To)
{
    return (Number >= From && Number <= To);
}
//-----------------------------------------;


short clsInputValidate::ReadShortNumber(const string& Message, const string& ErrorMessage)
{
    short Number;
    if (!Message.empty())
        cout << Message;

    while (!(cin >> Number))
    {
        cin.clear();                                         // لتصفير حالة الخطأ
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // لتنظيف البفر من الحروف المتبقية
        cout << ErrorMessage;
    }
    return Number;
}
int clsInputValidate::ReadIntNumber(const string& Message, const string& ErrorMessage)
{
    int Number;
    if (!Message.empty())
        cout << Message;

    while (!(cin >> Number))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ErrorMessage;
    }
    return Number;
}
double clsInputValidate::ReadDblNumber(const string& Message, const string& ErrorMessage)
{
    double Number;
    if (!Message.empty())
        cout << Message;

    while (!(cin >> Number))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ErrorMessage;
    }
    return Number;
}
//---------------------------------------------------------;


short clsInputValidate::ReadShortNumberBetween(short From, short To)
{
    string PromptMsg = "\nPlease enter a number between [" + to_string(From) + " and " + to_string(To) + "]:   ";
    short Number = ReadShortNumber(PromptMsg);

    while (!IsNumberBetween(Number, From, To))
        Number = ReadShortNumber(PromptMsg);

    return Number;
}
int clsInputValidate::ReadIntNumberBetween(int From, int To)
{
    string PromptMsg = "Please enter a number between [" + to_string(From) + " and " + to_string(To) + "]:   ";
    int Number = ReadIntNumber(PromptMsg);

    while (!IsNumberBetween(Number, From, To))
        Number = ReadIntNumber(PromptMsg);

    return Number;
}
double clsInputValidate::ReadDblNumberBetween(int From, int To)
{
    string PromptMsg = "Please enter a number between [" + to_string(From) + " and " + to_string(To) + "]:   ";
    double Number = ReadDblNumber(PromptMsg);

    while (!IsNumberBetween(Number, From, To))
        Number = ReadDblNumber(PromptMsg);

    return Number;
}
//-----------------------------------------;


bool clsInputValidate::IsDateBetween(clsDate Date, clsDate From, clsDate To)
{
    if (clsDate::IsDate1AfterDate2(From, To))
        clsDate::SwapDates(From, To);

    bool IsAfterOrEqualFrom = clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From);
    bool IsBeforeOrEqualTo = clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To);

    return (IsAfterOrEqualFrom && IsBeforeOrEqualTo);
}

string clsInputValidate::ReadString(const string& Msg)
{
    string str;
    cout << Msg;
    getline(cin >> ws, str);

    return str;
}
