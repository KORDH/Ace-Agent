#pragma once
#include <string>
using namespace std;

enum class Command
{
    INVALID,
    ADD,
    DEL,
    SCH,
    MOD,
};

struct Name
{
    string first;
    string last;
};

struct Birthday
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct PhoneNumber
{
    unsigned int mid;
    unsigned int last;
};

enum class CareerLevel
{
    INVALID,
    CL1,
    CL2,
    CL3,
    CL4,
};

enum class CertiLevel
{
    INVALID,
    ADV,
    PRO,
    EX,
};

enum class SelectType
{
    INVALID,
    EMPLOYEE_NUMBER,
    NAME,
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
    CERTI_LEVEL,
};

struct EmployeeInformation 
{
    unsigned int employeeNumber;
    Name name;
    CareerLevel careerLevel;
    PhoneNumber phoneNumber;
    Birthday birthday;
    CertiLevel certiLevel;
};