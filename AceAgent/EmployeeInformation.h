#pragma once
#include <string>

using namespace std;

enum class CareerLevel
{
	CL1,
	CL2,
	CL3,
	CL4,
	NONE,
};

enum class CertiLevel
{
	ADV,
	PRO,
	EX,
	NONE
};

struct Name
{
	string first;
	string last;
};

struct PhoneNumber
{
	unsigned int mid;
	unsigned int last;
};

class Birthday
{
public:
	Birthday() : year_{ 0 }, month_{ 0 }, day_{ 0 } {}
	Birthday(unsigned int year, unsigned int month, unsigned int day)
		: year_{ year }, month_{ month }, day_{ day }
	{}

	unsigned int getYear()
	{
		return year_;
	}
	unsigned int getMonth()
	{
		return month_;
	}unsigned int getDay()
	{
		return day_;
	}
	void setYear(unsigned int year)
	{
		year_ = year;
	}
	void setMonth(unsigned int month)
	{
		month_ = month;
	}
	void setDay(unsigned int day)
	{
		day_ = day;
	}
public:
	unsigned int year_;
	unsigned int month_;
	unsigned int day_;
};

class EmployeeInformation
{

public:
	EmployeeInformation(unsigned int employeeNumber, string firstName, string lastName,
		CareerLevel careerLevel, unsigned int midPhoneNumber, unsigned int lastPhoneNumber,
		unsigned int  yearOfBirthday, unsigned int  monthOfBirthday, unsigned int  dayOfBirthday, CertiLevel certiLevel) :
		employeeNumber_{ employeeNumber },
		name_{ firstName,lastName },
		careerLevel_{ careerLevel },
		phoneNumber_{ midPhoneNumber, lastPhoneNumber },
		birthday_(yearOfBirthday, monthOfBirthday, dayOfBirthday),
		certiLevel_{ certiLevel }
	{
	}

	unsigned int getEmployeeNumber()
	{
		return employeeNumber_;
	}
	string getFirstName()
	{
		return name_.first;
	}
	string getLastName()
	{
		return name_.last;
	}
	CareerLevel getCareerLevel()
	{
		return careerLevel_;
	}
	unsigned int getMidPhoneNumber()
	{
		return phoneNumber_.mid;
	}
	unsigned int getLastPhoneNumber()
	{
		return phoneNumber_.last;
	}
	Birthday getBirthday()
	{
		return birthday_;
	}
	CertiLevel getCertiLevel()
	{
		return certiLevel_;
	}
	void setFirstName(string firstName)
	{
		name_.first = firstName;
	}
	void setLastName(string lastName)
	{
		name_.last = lastName;
	}
	void setName(Name name)
	{
		name_.first = name.first;
		name_.last = name.last;
	}
	void setCareerLevel(CareerLevel careerLevel)
	{
		careerLevel_ = careerLevel;
	}
	void setMidPhoneNumber(unsigned int midPhoneNumber)
	{
		phoneNumber_.mid = midPhoneNumber;
	}
	void setLastPhoneNumber(unsigned int lastPhoneNumber)
	{
		phoneNumber_.last = lastPhoneNumber;
	}
	void setYearOfBirthday(Birthday birthday)
	{
		birthday_.setYear(birthday.getYear());
	}
	void setMonthOfBirthday(Birthday birthday)
	{
		birthday_.setMonth(birthday.getMonth());
	}
	void setDayOfBirthday(Birthday birthday)
	{
		birthday_.setDay(birthday.getDay());
	}
	void setPhoneNumber(PhoneNumber phoneNumber)
	{
		phoneNumber_.mid = phoneNumber.mid;
		phoneNumber_.last = phoneNumber.last;
	}
	void setBirthday(Birthday birthday)
	{
		birthday_.year_ = birthday.year_;
		birthday_.month_ = birthday.month_;
		birthday_.day_ = birthday.day_;
	}
	void setCertiLevel(CertiLevel certiLevel)
	{
		certiLevel_ = certiLevel;
	}
public:
	unsigned int employeeNumber_;
	Name name_;
	CareerLevel careerLevel_;
	PhoneNumber phoneNumber_;
	Birthday birthday_;
	CertiLevel certiLevel_;
};
