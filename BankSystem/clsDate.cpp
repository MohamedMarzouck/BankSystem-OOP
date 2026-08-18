
#include "clsDate.h"
// DayOfWeekOrder;
// GetSystemDaye;

clsDate::clsDate()
{
	time_t t = time(0);
	tm* now = localtime(&t);

	_Day = now->tm_mday;
	_Month = now->tm_mon + 1;
	_Year = now->tm_year + 1900;
}
clsDate::clsDate(short Day, short Month, short Year) : _Day(Day), _Month(Month), _Year(Year)
{
}
clsDate::clsDate(string sDate)
{
	vector <string> vDate = clsString::_Split(sDate);

	_Day = stoi(vDate[0]);
	_Month = stoi(vDate[1]);
	_Year = stoi(vDate[2]);
}
clsDate::clsDate(short DaysOrderInYear, short Year)
{
	clsDate Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
	_Day = Date.Day;
	_Month = Date.Month;
	_Year = Date.Year;
}



void clsDate::SetDay(short Day)
{
	_Day = Day;
}
void clsDate::SetMonth(short Month)
{
	_Month = Month;
}
void clsDate::SetYear(int Year)
{
	_Year = Year;
}
short clsDate::GetDay() const
{
	return _Day;
}
short clsDate::GetMonth() const
{
	return _Month;
}
int clsDate::GetYear() const
{
	return _Year;
}


string clsDate::DateToString(clsDate Date)
{
	return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
string clsDate::DateToString()
{
	return  DateToString(*this);
}
void clsDate::Print()
{
	cout << DateToString() << endl;
}



bool clsDate::IsValidDate(const clsDate& Date)
{
	return ((Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year)) && (Date.Day > 0) && (Date.Month <= 12) && (Date.Month > 0) && (Date.Year > 0));
}
bool clsDate::IsValid()
{
	return IsValidDate(*this);
}


clsDate clsDate::GetSystemDate()
{
	time_t t = time(0);
	tm* now = localtime(&t);

	short Day, Month, Year;

	Day = now->tm_mday;
	Month = now->tm_mon + 1;
	Year = now->tm_year + 1900;

	return clsDate(Day, Month, Year);        //* clsDate::GetSystemDate().Print();       ---> 15/8/2024;
}


bool clsDate::isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
bool clsDate::isLeapYear()
{
	return isLeapYear(_Year);
}


short clsDate::NumberOfDaysInAYear(short Year)
{
	return  isLeapYear(Year) ? 365 : 365;
}
short clsDate::NumberOfDaysInAYear()
{
	return  NumberOfDaysInAYear(_Year);
}


short clsDate::NumberOfHoursInAYear(short Year)
{
	return  NumberOfDaysInAYear(Year) * 24;
}
short clsDate::NumberOfHoursInAYear()
{
	return  NumberOfHoursInAYear(_Year);
}


int clsDate::NumberOfMinutesInAYear(short Year)
{
	return  NumberOfHoursInAYear(Year) * 60;
}
int clsDate::NumberOfMinutesInAYear()
{
	return  NumberOfMinutesInAYear(_Year);
}


int clsDate::NumberOfSecondsInAYear(short Year)
{
	return  NumberOfMinutesInAYear(Year) * 60;
}
int clsDate::NumberOfSecondsInAYear()
{
	return  NumberOfSecondsInAYear(_Year);
}


short clsDate::NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
short clsDate::NumberOfDaysInAMonth()
{
	return NumberOfDaysInAMonth(_Month, _Year);
}


short clsDate::NumberOfHoursInAMonth(short Month, short Year)
{
	return  NumberOfDaysInAMonth(Month, Year) * 24;
}
short clsDate::NumberOfHoursInAMonth()
{
	return  NumberOfDaysInAMonth(_Month, _Year) * 24;
}


int clsDate::NumberOfMinutesInAMonth(short Month, short Year)
{
	return  NumberOfHoursInAMonth(Month, Year) * 60;
}
int clsDate::NumberOfMinutesInAMonth()
{
	return  NumberOfHoursInAMonth(_Month, _Year) * 60;
}


int clsDate::NumberOfSecondsInAMonth(short Month, short Year)
{
	return  NumberOfMinutesInAMonth(Month, Year) * 60;
}
int clsDate::NumberOfSecondsInAMonth()
{
	return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
}


short clsDate::DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short clsDate::DayOfWeekOrder()
{
	return DayOfWeekOrder(_Day, _Month, _Year);
}



string clsDate::DayShortName(short Day, short Month, short Year)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
}
string clsDate::DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}
string clsDate::DayShortName()
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
}


string clsDate::MonthShortName(short Month)
{
	string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return (Months[Month - 1]);
}
string clsDate::MonthShortName()
{
	return MonthShortName(_Month);
}


void clsDate::PrintMonthCalendar(short Month, short Year)                   //TODO: clsDate::PrintMonthCalendar(8, 2024);
{
	int current = DayOfWeekOrder(1, Month, Year);
	int NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n  _________________________________\n");
}
void clsDate::PrintMonthCalendar()                                           //TODO: clsDate Date;
{                                                                            //TODO: Date.PrintMonthCalendar();
	PrintMonthCalendar(_Month, _Year);
}


void clsDate::PrintYearCalendar(int Year)
{
	printf("\n  _________________________________\n\n");
	printf("           Calendar - %d\n", Year);
	printf("  _________________________________\n");

	for (int i = 1; i <= 12; i++)
		PrintMonthCalendar(i, Year);
}
void clsDate::PrintYearCalendar()
{
	PrintYearCalendar(_Year);
}


short clsDate::DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = Day;
	for (int i = 1; i < Month; i++)
		TotalDays += NumberOfDaysInAMonth(i, Year);

	return TotalDays;
}
short clsDate::DaysFromTheBeginingOfTheYear()                  //TODO: cout << Date.DaysFromTheBeginingOfTheYear();
{
	return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
}





clsDate clsDate::GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)  // static;
{
	short Day = 1, Month = 1;
	while (DaysOrderInYear > NumberOfDaysInAYear(Year))
	{
		DaysOrderInYear -= NumberOfDaysInAYear(Year);
		Year++;
	}

	for (short i = 1; i < 13; i++)
	{
		if (DaysOrderInYear <= NumberOfDaysInAMonth(i, Year))
		{
			Day = DaysOrderInYear;
			Month = i;
			break;
		}
		else
			DaysOrderInYear -= NumberOfDaysInAMonth(i, Year);
	}

	return clsDate(Day, Month, Year);
}
clsDate clsDate::GetDateFromDayOrderInYear(short DaysOrderInYear) // NonStatic;
{
	while (DaysOrderInYear > NumberOfDaysInAYear(_Year))
	{
		DaysOrderInYear -= NumberOfDaysInAYear(_Year);
		Year++;
	}

	for (_Month = 1; _Month < 13; _Month++)
	{
		if (DaysOrderInYear <= NumberOfDaysInAMonth(_Month, _Year))
		{
			_Day = DaysOrderInYear;
			break;
		}
		else
			DaysOrderInYear -= NumberOfDaysInAMonth(_Month, _Year);
	}

	return *this;
}


bool clsDate::IsDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2)
{
	return (Date1.Year < Date2.Year) ||
		(Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
		(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}
bool clsDate::IsDateBeforeDate2(const clsDate& Date2)
{
	return  IsDate1BeforeDate2(*this, Date2);
}


bool clsDate::IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
{
	return ((Date1.Year != Date2.Year) || (Date1.Month != Date2.Month) || (Date1.Day != Date2.Day)) ? false : true;
}
bool clsDate::IsDateEqualDate2(const clsDate& Date2)
{
	return  IsDate1EqualDate2(*this, Date2);
}


bool clsDate::IsLastDayInMonth(const clsDate& Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool clsDate::IsLastDayInMonth()
{
	return IsLastDayInMonth(*this);
}
bool clsDate::IsLastMonthInYear(short Month)
{
	return (Month == 12);
}
bool clsDate::IsLastMonthInYear()
{
	return IsLastMonthInYear(_Month);
}


clsDate clsDate::AddOneDay(clsDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
		Date.Day++;

	return Date;
}
void clsDate::AddOneDay()
{
	*this = AddOneDay(*this);
}


void clsDate::SwapDates(clsDate& Date1, clsDate& Date2)
{
	clsDate TempDate;
	TempDate = Date1;
	Date1 = Date2;
	Date2 = TempDate;
}


int clsDate::GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay)
{
	int Days = 0;
	short SawpFlagValue = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SawpFlagValue = -1;
	}

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = AddOneDay(Date1);
	}

	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}
int clsDate::GetDifferenceInDays(clsDate Date2, bool IncludeEndDay)
{
	return GetDifferenceInDays(*this, Date2, IncludeEndDay);
}


//* No need to have nonStaticFunction for the object because it does not depend on any data from it;
short clsDate::CalculateMyAgeInDays(clsDate DateOfBirth)
{
	return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
}


clsDate clsDate::IncreaseDateByOneWeek(clsDate& Date)
{
	for (int i = 1; i <= 7; i++)
		Date = AddOneDay(Date);

	return Date;
}
void clsDate::IncreaseDateByOneWeek()
{
	IncreaseDateByOneWeek(*this);
}


clsDate clsDate::IncreaseDateByXWeeks(short Weeks, clsDate& Date)
{
	for (short i = 1; i <= Weeks; i++)
		Date = IncreaseDateByOneWeek(Date);

	return Date;
}
void clsDate::IncreaseDateByXWeeks(short Weeks)
{
	IncreaseDateByXWeeks(Weeks, *this);
}

clsDate clsDate::IncreaseDateByOneMonth(clsDate& Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
		Date.Month++;

	// Check last day in date should not exceed max days in the current month;
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
		Date.Day = NumberOfDaysInCurrentMonth;

	return Date;
}
void clsDate::IncreaseDateByOneMonth()
{
	IncreaseDateByOneMonth(*this);
}


clsDate clsDate::IncreaseDateByXDays(short Days, clsDate& Date)
{
	for (short i = 1; i <= Days; i++)
		Date = AddOneDay(Date);

	return Date;
}
void clsDate::IncreaseDateByXDays(short Days)
{
	IncreaseDateByXDays(Days, *this);
}


clsDate clsDate::IncreaseDateByXMonths(short Months, clsDate& Date)
{
	for (short i = 1; i <= Months; i++)
		Date = IncreaseDateByOneMonth(Date);

	return Date;
}
void clsDate::IncreaseDateByXMonths(short Months)
{
	IncreaseDateByXMonths(Months, *this);
}


clsDate clsDate::IncreaseDateByOneYear(clsDate& Date)
{
	Date.Year++;

	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
		Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

	return Date;
}
void clsDate::IncreaseDateByOneYear()
{
	IncreaseDateByOneYear(*this);
}


clsDate clsDate::IncreaseDateByXYears(short Years, clsDate& Date)
{
	Date.Year += Years;
	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
		Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	return Date;
}
void clsDate::IncreaseDateByXYears(short Years)
{
	IncreaseDateByXYears(Years);
}


clsDate clsDate::IncreaseDateByOneDecade(clsDate& Date)
{
	Date.Year += 10;
	return Date;
}
void clsDate::IncreaseDateByOneDecade()
{
	IncreaseDateByOneDecade(*this);
}


clsDate clsDate::IncreaseDateByXDecades(short Decade, clsDate& Date)
{
	Date.Year += Decade * 10;
	return Date;
}
void clsDate::IncreaseDateByXDecades(short Decade)
{
	IncreaseDateByXDecades(Decade, *this);
}


clsDate clsDate::IncreaseDateByOneCentury(clsDate& Date)
{
	Date.Year += 100;
	return Date;
}
void clsDate::IncreaseDateByOneCentury()
{
	IncreaseDateByOneCentury(*this);
}


clsDate clsDate::DecreaseDateByOneDay(clsDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else
		Date.Day--;

	return Date;
}
void clsDate::DecreaseDateByOneDay()
{
	DecreaseDateByOneDay(*this);
}


clsDate clsDate::DecreaseDateByOneWeek(clsDate& Date)
{
	for (int i = 1; i <= 7; i++)
		Date = DecreaseDateByOneDay(Date);

	return Date;
}
void clsDate::DecreaseDateByOneWeek()
{
	DecreaseDateByOneWeek(*this);
}


clsDate clsDate::DecreaseDateByXWeeks(short Weeks, clsDate& Date)
{
	for (short i = 1; i <= Weeks; i++)
		Date = DecreaseDateByOneWeek(Date);

	return Date;
}
void clsDate::DecreaseDateByXWeeks(short Weeks)
{
	DecreaseDateByXWeeks(Weeks, *this);
}


clsDate clsDate::DecreaseDateByOneMonth(clsDate& Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
		Date.Month--;

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}
void clsDate::DecreaseDateByOneMonth()
{
	DecreaseDateByOneMonth(*this);
}


clsDate clsDate::DecreaseDateByXDays(short Days, clsDate& Date)
{
	for (short i = 1; i <= Days; i++)
		Date = DecreaseDateByOneDay(Date);

	return Date;
}
void clsDate::DecreaseDateByXDays(short Days)
{
	DecreaseDateByXDays(Days, *this);
}


clsDate clsDate::DecreaseDateByXMonths(short Months, clsDate& Date)
{
	for (short i = 1; i <= Months; i++)
		Date = DecreaseDateByOneMonth(Date);

	return Date;
}
void clsDate::DecreaseDateByXMonths(short Months)
{
	DecreaseDateByXMonths(Months, *this);
}


clsDate clsDate::DecreaseDateByOneYear(clsDate& Date)
{
	Date.Year--;

	if (Date.Month > 12)
		Date.Month = 1;

	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
		Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);

	return Date;
}
void clsDate::DecreaseDateByOneYear()
{
	DecreaseDateByOneYear(*this);
}


clsDate clsDate::DecreaseDateByXYears(short Years, clsDate& Date)
{
	Date.Year -= Years;
	return Date;
}
void clsDate::DecreaseDateByXYears(short Years)
{
	DecreaseDateByXYears(Years, *this);
}


clsDate clsDate::DecreaseDateByOneDecade(clsDate& Date)
{
	Date.Year -= 10;
	return Date;
}
void clsDate::DecreaseDateByOneDecade()
{
	DecreaseDateByOneDecade(*this);
}


clsDate clsDate::DecreaseDateByXDecades(short Decades, clsDate& Date)
{
	Date.Year -= Decades * 10;
	return Date;
}
void clsDate::DecreaseDateByXDecades(short Decades)
{
	DecreaseDateByXDecades(Decades, *this);
}


short clsDate::IsEndOfWeek(clsDate Date)
{
	return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
}
short clsDate::IsEndOfWeek()
{
	return IsEndOfWeek(*this);
}


bool clsDate::IsWeekEnd(clsDate Date)
{
	short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year); 		//Weekends are Fri and Sat;
	return  (DayIndex == 5 || DayIndex == 6);
}
bool clsDate::IsWeekEnd()
{
	return  IsWeekEnd(*this);
}


bool clsDate::IsBusinessDay(clsDate Date)
{
	return !IsWeekEnd(Date);
}
bool clsDate::IsBusinessDay()
{
	return  IsBusinessDay(*this);
}


short clsDate::DaysUntilTheEndOfWeek(clsDate Date)
{
	return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}
short clsDate::DaysUntilTheEndOfWeek()
{
	return  DaysUntilTheEndOfWeek(*this);
}


short clsDate::DaysUntilTheEndOfMonth(const clsDate& Date)
{
	return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;

	//clsDate EndOfMontDate;
	//EndOfMontDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	//EndOfMontDate.Month = Date.Month;
	//EndOfMontDate.Year = Date.Year;

	//return GetDifferenceInDays(Date, EndOfMontDate, true);  //? return (NumberOfDaysInAMonth(Date._Year, Date.Year) - Date.Day);
}
short clsDate::DaysUntilTheEndOfMonth()
{
	return DaysUntilTheEndOfMonth(*this);
}


short clsDate::DaysUntilTheEndOfYear(clsDate Date1)
{
	clsDate EndOfYearDate;                                   //? return (NumberOfDaysInAYear(Date._Year) - DaysFromTheBeginingOfTheYear(Date.Day, DAte.Month, Date.Year));
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfYearDate, true);
}
short clsDate::DaysUntilTheEndOfYear()
{
	return  DaysUntilTheEndOfYear(*this);
}


short clsDate::CalculateBusinessDays(clsDate DateFrom, const clsDate& DateTo)
{
	short Days = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
			Days++;

		DateFrom = AddOneDay(DateFrom);
	}

	return Days;
}
short clsDate::CalculateBusinessDays(const clsDate& DateTo)
{
	return CalculateBusinessDays(*this, DateTo);
}


short clsDate::CalculateVacationDays(clsDate DateFrom, const clsDate& DateTo)
{
	short Days = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsWeekEnd(DateFrom))
			Days++;

		DateFrom = AddOneDay(DateFrom);
	}

	return Days;
}
short clsDate::CalculateVacationDays(const clsDate& DateTo)
{
	return CalculateVacationDays(*this, DateTo);
}


clsDate clsDate::CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
{
	while (VacationDays != 0)
	{
		if (IsBusinessDay(DateFrom))
			VacationDays--;

		DateFrom = AddOneDay(DateFrom);
	}

	while (IsWeekEnd(DateFrom))
		DateFrom = AddOneDay(DateFrom);

	return DateFrom;
}
clsDate clsDate::CalculateVacationReturnDate(short VacationDays)
{
	return CalculateVacationReturnDate(*this, VacationDays);
}


bool clsDate::IsDate1AfterDate2(clsDate Date1, clsDate Date2)
{
	return (Date1.Year > Date2.Year) ||
		(Date1.Year == Date2.Year && Date1.Month > Date2.Month) ||
		(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day);
}
bool clsDate::IsDateAfterDate2(clsDate Date2)
{
	return IsDate1AfterDate2(*this, Date2);
}

clsDate clsDate::StringToDateStructure(const vector<string>& vDate)
{
	clsDate Date;

	if (vDate[0].length() == 4)  //  yyyy/mm/dd;
	{
		Date.Year = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Day = stoi(vDate[2]);
	}
	else
	{
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);
	}

	return Date;
}
clsDate clsDate::StringToDateStructure(const string& str)
{
	vector<string> vDate = clsString::_Split(str, "/");
	return StringToDateStructure(vDate);
}


string clsDate::ReplaceWordInString(string str, const string& From, const string& To)
{
	size_t pos = 0;
	while ((pos = str.find(From, pos)) != string::npos)
	{
		str.replace(pos, From.length(), To);
		pos += To.length();
	}
	return str;
}

string clsDate::FormatDate(const clsDate& Date, string Format)
{
	Format = ReplaceWordInString(Format, "yyyy", to_string(Date.Year));
	Format = ReplaceWordInString(Format, "mm", to_string(Date.Month));
	Format = ReplaceWordInString(Format, "dd", to_string(Date.Day));
	return Format;
}



