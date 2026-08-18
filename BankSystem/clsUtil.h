#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "clsDate.h"




class clsUtil
{
public:
    enum enRandomCharacter
    {
        Digit = 1,
        CapitalLetter = 2,
        SmallLetter = 3,
        MixChars = 4
    };

    static void Srand();
    static int RandomNumber(int From, int To);
    static char GetRandomCharacter(enRandomCharacter Option);
    static string GenerateWord(enRandomCharacter Option, short WordSize = 5);
    static string GenerateKey(enRandomCharacter Option, short WordSize = 5, short KeySize = 4);
    static vector<string> GenerateKeys(enRandomCharacter Option, short WordSize = 5, short KeySize = 4, short KeysCount = 5);
    static void PrintVectorString(const vector<string>& vString);
    static void Swap(int& X, int& Z);
    static void Swap(float& X, float& Z);
    static void Swap(string& str1, string& str2);
    static void Swap(clsDate& Date1, clsDate& Date2);
    static void ShuffleArray(int Arr[], short Size);
    static void SHuffleStringArr(string Arr[], short Size);
    static void FillArrayWithRandomNumbers(int Arr[], short Size, short From, short To);
    static void FillArrayWithRandomWords(string Arr[], short Size, enRandomCharacter RandonChar, short WordSize);
    static string Tap(short NumberOfTabs);
    static string EncryptText(string Text, short EncryptionKey);
    static string DecryptText(string Text, short EncryptionKey);
    static string NumberToText(int Number);

};



//int main()
//{
//    clsUtil::Srand();
//    cout << clsUtil::CapitalLetter << "\n";
//    cout << clsUtil::GetRandomCharacter(clsUtil::SmallLetter) << "\n";
//    cout << clsUtil::GetRandomCharacter(clsUtil::MixChars) << "\n\n";
//    vector<string> vString = clsUtil::GenerateKeys(clsUtil::MixChars);
//    clsUtil::PrintVectorString(vString);
//
//    string Arr[5] = { "Ahmed", "Sherief", "Ibrahim", "Fathy", "Mohamed" };
//    clsUtil::SHuffleStringArr(Arr, 5);
//    for (short i = 0; i < 5; i++)
//        cout << Arr[i] << "\t";
//
//    cout << "\nText1" << clsUtil::Tap(2) << "Text2\n";
//    cout << endl;
//    string Name = "Mohamed Abu-Hadhoud";
//    string NameAfterAncryption = clsUtil::EncryptText(Name, 9);
//    cout << "\n" << NameAfterAncryption << endl;
//    cout << "\n" << clsUtil::DecryptText(NameAfterAncryption, 9) << endl;
//
//    system("pause>0");
//    return 0;
//}