#pragma once

#include <map>
#include "Type.h"

class DataManager
{
public:
    multimap<unsigned int, EmployeeInformation>& getEmployeeNumberMap() { return employeeNumberMap; }
    multimap<unsigned int, EmployeeInformation>& getCareerLevelMap() { return careerLevelMap; }
    multimap<unsigned int, EmployeeInformation>& getYearOfBirthdayMap() { return yearOfBirthdayMap; }
    multimap<unsigned int, EmployeeInformation>& getMonthOfBirthdayMap() { return monthOfBirthdayMap; }
    multimap<unsigned int, EmployeeInformation>& getDayOfBirthdayMap() { return dayOfBirthdayMap; }
    multimap<unsigned int, EmployeeInformation>& getCertiLevelMap() { return certiLevelMap; }
    multimap<string, EmployeeInformation>& getFirstNameMap() { return firstNameMap; }
    multimap<string, EmployeeInformation>& getLastNameMap() { return lastNameMap; }
    multimap<string, EmployeeInformation>& getMidPhoneNumberMap() { return midPhoneNumberMap; }
    multimap<string, EmployeeInformation>& getLastPhoneNumberMap() { return lastPhoneNumberMap; }

private:
    multimap<unsigned int, EmployeeInformation> employeeNumberMap;
    multimap<unsigned int, EmployeeInformation> careerLevelMap;
    multimap<unsigned int, EmployeeInformation> yearOfBirthdayMap;
    multimap<unsigned int, EmployeeInformation> monthOfBirthdayMap;
    multimap<unsigned int, EmployeeInformation> dayOfBirthdayMap;
    multimap<unsigned int, EmployeeInformation> certiLevelMap;
    multimap<string, EmployeeInformation> firstNameMap;
    multimap<string, EmployeeInformation> lastNameMap;
    multimap<string, EmployeeInformation> midPhoneNumberMap;
    multimap<string, EmployeeInformation> lastPhoneNumberMap;
};