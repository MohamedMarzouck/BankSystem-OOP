
#pragma once
#pragma warning(disable : 4996)


#include <iostream>
#include <string>
#include <vector>
#include "clsString.h"

using namespace std;


class clsDate
{
private:
	short _Day;
	short _Month;
	int   _Year;

public:
	clsDate();
	clsDate(short Day, short Month, short Year);
	clsDate(string sDate);
	clsDate(short DaysOrderInYear, short Year);



	void SetDay(short Day);
	void SetMonth(short Month);
	void SetYear(int Year);
	short GetDay() const;
	short GetMonth() const;
	int GetYear() const;
	__declspec(property(get = GetDay, put = SetDay)) short Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
	__declspec(property(get = GetYear, put = SetYear)) int Year;
	//-----------;

	static clsDate GetSystemDate();
	static string DateToString(clsDate Date);
	string DateToString();
	void Print();



	static bool IsValidDate(const clsDate& Date);
	bool IsValid();

	static bool isLeapYear(short Year);
	bool isLeapYear();

	static short NumberOfDaysInAYear(short Year);
	short NumberOfDaysInAYear();

	static short NumberOfHoursInAYear(short Year);
	short NumberOfHoursInAYear();

	static int NumberOfMinutesInAYear(short Year);
	int NumberOfMinutesInAYear();

	static int NumberOfSecondsInAYear(short Year);
	int NumberOfSecondsInAYear();

	static short NumberOfDaysInAMonth(short Month, short Year);
	short NumberOfDaysInAMonth();

	static short NumberOfHoursInAMonth(short Month, short Year);
	short NumberOfHoursInAMonth();

	static int NumberOfMinutesInAMonth(short Month, short Year);
	int NumberOfMinutesInAMonth();

	static int NumberOfSecondsInAMonth(short Month, short Year);
	int NumberOfSecondsInAMonth();

	static short DayOfWeekOrder(short Day, short Month, short Year);
	short DayOfWeekOrder();

	static string DayShortName(short Day, short Month, short Year);
	static string DayShortName(short DayOfWeekOrder);
	string DayShortName();

	static string MonthShortName(short Month);
	string MonthShortName();

	static void PrintMonthCalendar(short Month, short Year);
	void PrintMonthCalendar();

	static void PrintYearCalendar(int Year);
	void PrintYearCalendar();

	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
	short DaysFromTheBeginingOfTheYear();

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year);
	clsDate GetDateFromDayOrderInYear(short DateOrderInYear);

	clsDate AddDays(short Days);

	static bool IsDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2);
	bool IsDateBeforeDate2(const clsDate& Date2);


	static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2);
	bool IsDateEqualDate2(const clsDate& Date2);

	static bool IsLastDayInMonth(const clsDate& Date);
	bool IsLastDayInMonth();
	static bool IsLastMonthInYear(short Month);
	bool IsLastMonthInYear();


	static clsDate AddOneDay(clsDate Date);
	void AddOneDay();

	static void SwapDates(clsDate& Date1, clsDate& Date2);


	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false);
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false);

	static short CalculateMyAgeInDays(clsDate DateOfBirth);

	static clsDate IncreaseDateByOneWeek(clsDate& Date);
	void IncreaseDateByOneWeek();

	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date);
	void IncreaseDateByXWeeks(short Weeks);

	clsDate IncreaseDateByOneMonth(clsDate& Date);
	void IncreaseDateByOneMonth();

	clsDate IncreaseDateByXDays(short Days, clsDate& Date);
	void IncreaseDateByXDays(short Days);

	clsDate IncreaseDateByXMonths(short Months, clsDate& Date);
	void IncreaseDateByXMonths(short Months);

	static clsDate IncreaseDateByOneYear(clsDate& Date);
	void IncreaseDateByOneYear();

	clsDate IncreaseDateByXYears(short Years, clsDate& Date);
	void IncreaseDateByXYears(short Years);

	clsDate IncreaseDateByOneDecade(clsDate& Date);
	void IncreaseDateByOneDecade();


	clsDate IncreaseDateByXDecades(short Decade, clsDate& Date);
	void IncreaseDateByXDecades(short Decade);
	clsDate IncreaseDateByOneCentury(clsDate& Date);
	void IncreaseDateByOneCentury();

	//? Decrease:-
	static clsDate DecreaseDateByOneDay(clsDate Date);
	void DecreaseDateByOneDay();

	static clsDate DecreaseDateByOneWeek(clsDate& Date);
	void DecreaseDateByOneWeek();

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date);
	void DecreaseDateByXWeeks(short Weeks);

	static clsDate DecreaseDateByOneMonth(clsDate& Date);
	void DecreaseDateByOneMonth();

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date);
	void DecreaseDateByXDays(short Days);

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date);
	void DecreaseDateByXMonths(short Months);

	static clsDate DecreaseDateByOneYear(clsDate& Date);
	void DecreaseDateByOneYear();

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date);
	void DecreaseDateByXYears(short Years);

	static clsDate DecreaseDateByOneDecade(clsDate& Date);
	void DecreaseDateByOneDecade();

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date);
	void DecreaseDateByXDecades(short Decades);

	static short IsEndOfWeek(clsDate Date);
	short IsEndOfWeek();

	static bool IsWeekEnd(clsDate Date);
	bool IsWeekEnd();

	static bool IsBusinessDay(clsDate Date);
	bool IsBusinessDay();

	static short DaysUntilTheEndOfWeek(clsDate Date);
	short DaysUntilTheEndOfWeek();


	static short DaysUntilTheEndOfMonth(const clsDate& Date);
	short DaysUntilTheEndOfMonth();

	static short DaysUntilTheEndOfYear(clsDate Date1);
	short DaysUntilTheEndOfYear();


	static short CalculateBusinessDays(clsDate DateFrom, const clsDate& DateTo);
	short CalculateBusinessDays(const clsDate& DateTo);

	static short CalculateVacationDays(clsDate DateFrom, const clsDate& DateTo);
	short CalculateVacationDays(const clsDate& DateTo);

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays);
	clsDate CalculateVacationReturnDate(short VacationDays);

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2);
	bool IsDateAfterDate2(clsDate Date2);

	static clsDate StringToDateStructure(const vector<string>& vDate);
	clsDate clsDateStringToDateStructure(const vector<string>& vDate);
	clsDate StringToDateStructure(const string& str);

	static string ReplaceWordInString(string str, const string& From, const string& To);

	static string FormatDate(const clsDate& Date, string Format = "dd/mm/yyyy");

};

