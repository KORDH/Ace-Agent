#pragma once
#include <string>

using namespace std;

enum class CareerLevel
{
	CL1,
	CL2,
	CL3,
	CL4,
};

enum class CertiLevel
{
	ADV,
	PRO,
	EX
};

class Birthday
{
public:
	Birthday(unsigned int year, unsigned int month, unsigned int day)
		: year_{ year }, month_{ month }, day_{ day }
	{}
private:
	unsigned int year_;
	unsigned int month_;
	unsigned int day_;
};

class EmployeeInfomation
{

public:
	EmployeeInfomation(unsigned int employeeNumber, string firstName, string lastName,
		CareerLevel careerLevel, unsigned int midPhoneNumber, unsigned int lastPhoneNumber,
		unsigned int  yearOfBirthday, unsigned int  monthOfBirthday, unsigned int  dayOfBirthday, CertiLevel certiLevel) :
		employeeNumber_{ employeeNumber },
		firstName_{ firstName },
		lastName_{ lastName },
		careerLevel_{ careerLevel },
		midPhoneNumber_{ midPhoneNumber },
		lastPhoneNumber_{ lastPhoneNumber },
		birthday_(yearOfBirthday, monthOfBirthday, dayOfBirthday),
		certiLevel_{ certiLevel }
	{
	}

private:
	unsigned int employeeNumber_;
	string firstName_;
	string lastName_;
	CareerLevel careerLevel_;
	unsigned int midPhoneNumber_;
	unsigned int lastPhoneNumber_;
	Birthday birthday_;
	CertiLevel certiLevel_;
};
