
#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
//#include <limits>


using namespace std;


class clsInputValidate
{
public:

    static bool IsNumberBetween(short Number, short From, short To);
    static bool IsNumberBetween(int Number, int From, int To);
    static bool IsNumberBetween(double Number, int From, int To);
    // - ----------------------------------------------------------;


    static short ReadShortNumber(const string& Message = "", const string& ErrorMessage = "Invalid Number, Enter again:   ");
    static int ReadIntNumber(const string& Message = "", const string& ErrorMessage = "Invalid Number, Enter again:   ");
    static double ReadDblNumber(const string& Message = "", const string& ErrorMessage = "Invalid Number, Enter again:   ");
    // - -------------------------------------------------------------------------------------------------------------------;


    static short ReadShortNumberBetween(short From, short To);
    static int ReadIntNumberBetween(int From, int To);
    static double ReadDblNumberBetween(int From, int To);
    // - ----------------------------------------------------;


    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);

    static string ReadString(const string& Msg);

};

