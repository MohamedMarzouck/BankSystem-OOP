#pragma once

#include <iostream>  
#include <vector> 

using namespace std;
const string Delim = "#||#";



class clsString
{
    string _Value;
public:
    clsString();
    clsString(string Value);
    void SetValue(const string& Value);
    string GetValue();
    __declspec(property(get = GetValue, put = SetValue)) string Value;
    //---------------------------------------------------------------;

    static short Length(const string& str);
    short Length();

    static void Get_FirstLetter(const string& str);
    void Get_FirstLetter();

    static void PrintWordString(const string& str);
    void PrintWordString();

    static short CountWords(const string& str);
    short CountWords();

    static string UpperFirstLetterOfEachWord(string str);
    void  UpperFirstLetterOfEachWord();

    static string LowerFirstLetterOfEachWord(string str);
    void  LowerFirstLetterOfEachWord();

    static string  UpperAllString(string str);
    void  UpperAllString();

    static string  LowerAllString(string str);
    void  LowerAllString();

    static char  InvertLetterCase(char char1);
    static string  InvertAllLettersCase(string str);
    void  InvertAllLettersCase();

    static short CountSpecificLetter(const string& str, char Letter, bool MatchCase = true);
    short  CountSpecificLetter(char Letter, bool MatchCase = true);

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
    static short CountLetters(const string& str, enWhatToCount WhatToCount = enWhatToCount::All);

    static short  CountCapitalLetters(const string& str);
    short  CountCapitalLetters();

    static short  CountSmallLetters(const string& str);
    short CountSmallLetters();

    static bool IsVowel(char Letter);
    static short CountVowels(const string& S1);
    short  CountVowels();

    static void PrintVowelLetter(const string& str);
    void PrintVowelLetter();

    static vector<string> _Split(const string& str, const string& Delim = "#||#");
    vector<string> _Split();

    static string TrimLeft(string str);
    void TrimLeft();

    static string TrimRight(string str);
    void TrimRight();


    static string Trim(string str);
    void Trim();

    static string JoinString(const vector<string>& vString);
    // void JoinString(const vector<string>& vString); 

    static string ReverseWordsInString(const string& S1);
    void ReverseWordsInString();

    static string ReplaceWord(const string& S1, const string& ReplaceFrom, const string& ReplaceTo, bool MatchCase = false);
    string ReplaceWord(string StringToReplace, string sRepalceTo);

    static string RemovePunctuations(const string& str);
    void RemovePunctuations();

};

