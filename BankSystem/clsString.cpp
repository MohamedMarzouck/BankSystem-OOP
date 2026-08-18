#include "clsString.h"

clsString::clsString() : _Value("")
{
}
clsString::clsString(string Value) : _Value(Value)
{
}


void clsString::SetValue(const string& Value)
{
    _Value = Value;
}
string clsString::GetValue()
{
    return _Value;
}


short clsString::Length(const string& str)
{
    return str.length();
}
short clsString::Length()
{
    return _Value.length();
}


void clsString::Get_FirstLetter(const string& str)
{
    bool IsFirstLetter = true;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isspace(str[i]) && IsFirstLetter)
            cout << str[i] << "\n";

        IsFirstLetter = (isspace(str[i]) ? true : false);
    }
}
void clsString::Get_FirstLetter()
{
    Get_FirstLetter(_Value);
}


void clsString::PrintWordString(const string& str)
{
    string sWord;
    short pos = 0;
    short prev = 0;

    while ((pos = str.find(Delim)) != std::string::npos)
    {
        sWord = str.substr(prev, pos - prev);
        prev = pos + Delim.length();

        if (!sWord.empty())
            cout << sWord << endl;
    }

    string LastWord = str.substr(prev);
    if (!LastWord.empty())
        cout << LastWord << "\n";
}
void clsString::PrintWordString()
{
    PrintWordString(_Value);
}


short clsString::CountWords(const string& str)
{
    string sWord;
    short pos = 0;
    short prev = 0;
    short Counter = 0;

    while ((pos = str.find(Delim)) != std::string::npos)
    {
        sWord = str.substr(prev, pos - prev);
        prev = pos + Delim.length();

        if (!sWord.empty())
            Counter++;
    }

    string LastWord = str.substr(prev);
    if (!LastWord.empty())
        Counter++;

    return Counter;
}
short clsString::CountWords()
{
    return CountWords(_Value);
}


string clsString::UpperFirstLetterOfEachWord(string str)
{
    bool isFirstLetter = true;

    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
            str[i] = toupper(str[i]);

        isFirstLetter = (str[i] == ' ' ? true : false);
    }

    return str;
}
void clsString::UpperFirstLetterOfEachWord()
{
    _Value = UpperFirstLetterOfEachWord(_Value);    //***************;
}

string clsString::LowerFirstLetterOfEachWord(string str)
{
    bool isFirstLetter = true;

    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
            str[i] = tolower(str[i]);

        isFirstLetter = (str[i] == ' ' ? true : false);
    }

    return str;
}
void clsString::LowerFirstLetterOfEachWord()
{
    _Value = LowerFirstLetterOfEachWord(_Value);
}


string clsString::UpperAllString(string str)
{
    for (short i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);

    return str;
}
void clsString::UpperAllString()
{
    _Value = UpperAllString(_Value);
}


string clsString::LowerAllString(string str)
{
    for (short i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);

    return str;
}
void clsString::LowerAllString()
{
    _Value = LowerAllString(_Value);
}


char clsString::InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
string clsString::InvertAllLettersCase(string str)
{
    for (short i = 0; i < str.length(); i++)
        str[i] = InvertLetterCase(str[i]);

    return str;
}
void clsString::InvertAllLettersCase()
{
    _Value = InvertAllLettersCase(_Value);
}


short clsString::CountSpecificLetter(const string& str, char Letter, bool MatchCase)
{
    short Counter = 0;

    for (short i = 0; i < str.length(); i++)
        if (MatchCase)
        {
            if (str[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(str[i]) == tolower(Letter))
                Counter++;
        }

    return Counter;
}
short clsString::CountSpecificLetter(char Letter, bool MatchCase)
{
    return CountSpecificLetter(_Value, Letter, MatchCase);
}


short clsString::CountLetters(const string& str, enWhatToCount WhatToCount)
{
    if (WhatToCount == enWhatToCount::All)
        return str.length();

    short Counter = 0;

    for (short i = 0; i < str.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(str[i]))
            Counter++;

        if (WhatToCount == enWhatToCount::SmallLetters && islower(str[i]))
            Counter++;
    }

    return Counter;
}


short clsString::CountCapitalLetters(const string& str)
{
    short Counter = 0;

    for (short i = 0; i < str.length(); i++)
        if (isupper(str[i]))
            Counter++;

    return Counter;
}
short clsString::CountCapitalLetters()
{
    return CountCapitalLetters(_Value);
}


short clsString::CountSmallLetters(const string& str)
{
    short Counter = 0;

    for (short i = 0; i < str.length(); i++)
        if (islower(str[i]))
            Counter++;

    return Counter;
}
short clsString::CountSmallLetters()
{
    return CountSmallLetters(_Value);
}


bool clsString::IsVowel(char Letter)
{
    Letter = tolower(Letter);
    return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}
short clsString::CountVowels(const string& S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
        if (IsVowel(S1[i]))
            Counter++;

    return Counter;
}
short clsString::CountVowels()
{
    return CountVowels(_Value);
}


void clsString::PrintVowelLetter(const string& str)
{
    for (size_t i = 0; i < str.length(); i++)
        if (IsVowel(str[i]))
            cout << str[i];
}
void clsString::PrintVowelLetter()
{
    return PrintVowelLetter(_Value);
}


vector<string> clsString::_Split(const string& str, const string& Delim)
{
    size_t pos = 0;
    size_t prev = 0;
    string sWord = "";
    vector<string> vString;

    while ((pos = str.find(Delim, prev)) != std::string::npos)
    {
        sWord = str.substr(prev, pos - prev);
        prev = pos + Delim.length();

        if (!sWord.empty())
            vString.push_back(sWord);
    }
    string lWord = str.substr(prev);
    if (!lWord.empty())
        vString.push_back(lWord);

    return vString;
}
vector<string> clsString::_Split()
{
    return _Split(_Value);
}


string clsString::TrimLeft(string str)
{
    for (short i = 0; i < str.length(); i++)
        if (str[i] != ' ')
        {
            return str.substr(i);         //******** str.substr(i, str.length() - i) *****;
        }

    return "";
}

void clsString::TrimLeft()
{
    _Value = TrimLeft(_Value);
}


string clsString::TrimRight(string str)
{
    for (short i = str.length() - 1; i >= 0; i--)
        if (str[i] != ' ')
        {
            return str.substr(0, i + 1);  // ********** (short i = str.length() - 1; i >= 0; i--) &&& str.substr(0, i + 1)**********;
        }

    return "";
}
void clsString::TrimRight()
{
    _Value = TrimRight(_Value);
}


string clsString::Trim(string str)
{
    return (TrimLeft(TrimRight(str)));
}
void clsString::Trim()
{
    _Value = Trim(_Value);
}


string clsString::JoinString(const vector<string>& vString)
{
    string str = "";

    for (const string& s : vString)
        str = str + s + Delim;

    return str.substr(0, str.length() - Delim.length());
}
//void clsString::JoinString(const vector<string>& vString)
//{
//    _Value = JoinString(vString);
//}


string clsString::ReverseWordsInString(const string& S1)
{
    string str = "";
    vector<string> vString = _Split(S1);
    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;
        str += *iter + " ";
    }

    str = str.substr(0, str.length() - 1);
    return str;
}
void clsString::ReverseWordsInString()
{
    _Value = ReverseWordsInString(_Value);
}


string clsString::ReplaceWord(const string& S1, const string& ReplaceFrom, const string& ReplaceTo, bool MatchCase)
{
    vector<string> vString = _Split(S1);

    for (string& str : vString)
        if (MatchCase)
        {
            if (str == ReplaceFrom)
                str = ReplaceTo;
        }
        else
        {
            if (LowerAllString(str) == LowerAllString(ReplaceFrom)) //* Tolower() --> OneCharacter;
                str = ReplaceTo;
        }

    return JoinString(vString);
}
string clsString::ReplaceWord(string StringToReplace, string sRepalceTo)
{
    return ReplaceWord(_Value, StringToReplace, sRepalceTo);
}


string clsString::RemovePunctuations(const string& str)
{
    string S2 = "";

    for (short i = 0; i < str.length(); i++)
        if (!ispunct(str[i]))
            S2 += str[i];

    return S2;
}
void clsString::RemovePunctuations()
{
    _Value = RemovePunctuations(_Value);
}




