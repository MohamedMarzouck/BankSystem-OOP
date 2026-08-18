
#include "clsUtil.h"
#include <cstdlib>
#include <ctime>





void clsUtil::Srand()
{
    srand((unsigned)time(NULL));
}

int clsUtil::RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char clsUtil::GetRandomCharacter(enRandomCharacter Option)
{
    switch (Option)
    {
    case Digit:
        return (char)RandomNumber(48, 57);
    case CapitalLetter:
        return (char)RandomNumber(65, 90);
    case SmallLetter:
        return (char)RandomNumber(97, 122);
    case MixChars:
        return GetRandomCharacter(static_cast<enRandomCharacter>(RandomNumber(1, 4)));  //**************************;
    default:
        return (char)RandomNumber(65, 90);
    }
}

string clsUtil::GenerateWord(enRandomCharacter Option, short WordSize)
{
    string Word = "";
    for (short i = 1; i <= WordSize; i++)
        Word += GetRandomCharacter(Option);

    return Word;
}

string clsUtil::GenerateKey(enRandomCharacter Option, short WordSize, short KeySize)
{
    string Key = "";
    for (short i = 1; i <= KeySize; i++)
    {
        Key += GenerateWord(Option, WordSize);
        if (i < KeySize)
            Key += "-";
    }
    return Key;
}

vector<string> clsUtil::GenerateKeys(enRandomCharacter Option, short WordSize, short KeySize, short KeysCount)
{
    vector<string> vKeys;
    for (short i = 1; i <= KeysCount; i++)
        vKeys.push_back(GenerateKey(Option, WordSize, KeySize));

    return vKeys;
}
void clsUtil::PrintVectorString(const vector<string>& vString)
{
    for (const string& str : vString)
        cout << str << endl;
}

void clsUtil::Swap(int& X, int& Z)
{
    int Temp;
    Temp = X;
    X = Z;
    Z = Temp;
}

void clsUtil::Swap(float& X, float& Z)
{
    float Temp;
    Temp = X;
    X = Z;
    Z = Temp;
}

void clsUtil::Swap(string& str1, string& str2)
{
    string Temp;
    Temp = str1;
    str1 = str2;
    str2 = Temp;
}

void clsUtil::Swap(clsDate& Date1, clsDate& Date2)
{
    clsDate Temp;
    Temp.Day = Date1.Day;
    Temp.Month = Date1.Month;
    Temp.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = Temp.Day;
    Date2.Month = Temp.Month;
    Date2.Year = Temp.Year;
}

void clsUtil::ShuffleArray(int Arr[], short Size)
{
    for (short i = Size - 1; i >= 0; i--)
    {
        int k = RandomNumber(0, i);
        Swap(Arr[i], Arr[k]);
    }
}

void clsUtil::SHuffleStringArr(string Arr[], short Size)
{
    for (short i = Size - 1; i >= 0; i--)
    {
        int k = RandomNumber(0, i);
        Swap(Arr[i], Arr[k]);
    }
}

void clsUtil::FillArrayWithRandomNumbers(int Arr[], short Size, short From, short To)
{
    for (short i = 0; i < Size; i++)
        Arr[i] = RandomNumber(From, To);
}

void clsUtil::FillArrayWithRandomWords(string Arr[], short Size, enRandomCharacter RandonChar, short WordSize)
{
    for (short i = 0; i < Size; i++)
        Arr[i] = GenerateWord(RandonChar, WordSize);
}

string clsUtil::Tap(short NumberOfTabs)
{
    string T = "";
    for (short i = 0; i < NumberOfTabs; i++)
        T += "\t";

    return T;
}

string clsUtil::EncryptText(string Text, short EncryptionKey)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] -= EncryptionKey;

    return Text;
}

string clsUtil::DecryptText(string Text, short EncryptionKey)
{
    for (short i = 0; i < Text.length(); i++)
        Text[i] += EncryptionKey;

    return Text;
}

string clsUtil::NumberToText(int Number)
{
    if (Number == 0)
        return "";

    if (Number >= 1 && Number < 20)
    {
        string Arr[] = { "", "One", "Tow", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                         "Tewelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen" };

        return Arr[Number];
    }

    if (Number >= 20 && Number < 100)
    {
        string Arr[] = { "", "", "Twinty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };
        return Arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number < 200)
        return "One Hundred " + NumberToText(Number % 100);
    if (Number >= 200 && Number < 1000)
        return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);

    if (Number >= 1000 && Number < 2000)
        return "One Thousand " + NumberToText(Number % 1000);
    if (Number >= 2000 && Number < 1000000)
        return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
}




