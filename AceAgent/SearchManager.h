#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct EmployeeInformation
{
	unsigned int employeeNumber_;
	unsigned int yearOfBirthday;
	unsigned int monthOfBirthday;
	unsigned int dayOfBirthday;
	unsigned int careerLevel_;
	string certiLevel_;
	string fullName;
	string firstName;
	string lastName;
	string phoneNumber_;
	string midPhoneNumber;
	string lastPhoneNumber;
	string birthday_;
};


enum class DataType
{
	EMPLOYEE_NUMBER,
	FULL_NAME,
	FIRST_NAME,
	LAST_NAME,
	CAREER_LEVEL,
	PHONE_NUMBER,
	MID_PHONE_NUMBER,
	LAST_PHONE_NUMBER,
	BIRTHDAY,
	YEAR_OF_BIRTHDAY,
	MONTH_OF_BIRTHDAY,
	DAY_OF_BIRTHDAY,
	CERTI_LEVEL
};

multimap<unsigned int, EmployeeInformation> employeeNumberMap;
multimap<unsigned int, EmployeeInformation> careerLevelMap;
multimap<unsigned int, EmployeeInformation> yearOfBirthdayMap;
multimap<unsigned int, EmployeeInformation> monthOfBirthdayMap;
multimap<unsigned int, EmployeeInformation> dayOfBirthdayMap;
multimap<string, EmployeeInformation> certiLevelMap;
multimap<string, EmployeeInformation> fullNameMap;
multimap<string, EmployeeInformation> firstNameMap;
multimap<string, EmployeeInformation> lastNameMap;
multimap<string, EmployeeInformation> phoneNumberMap;
multimap<string, EmployeeInformation> midPhoneNumberMap;
multimap<string, EmployeeInformation> lastPhoneNumberMap;
multimap<string, EmployeeInformation> birthdayMap;


#define RANGE 69000000

bool cmp(const EmployeeInformation& a, const EmployeeInformation& b)
{
	if (a.employeeNumber_ >= RANGE && b.employeeNumber_ >= RANGE) {
		if (a.employeeNumber_ > b.employeeNumber_)
			return false;
	}
	else if (a.employeeNumber_ >= RANGE) {
		return true;
	}
	else if (b.employeeNumber_ >= RANGE) {
		return false;
	}
	else
	{
		if (a.employeeNumber_ > b.employeeNumber_)
			return false;
	}

	return true;
}


class SearchManager {
public:
	vector<EmployeeInformation> SearchEmployeeData(DataType searchType, unsigned int keyData);
	vector<EmployeeInformation> SearchEmployeeData(DataType searchType, string keyData);
	multimap<unsigned int, EmployeeInformation> getIntegerDataMap(DataType searchType);
	multimap<string, EmployeeInformation> getCharacterDataMap(DataType searchType);
private:

};