#pragma once
#include <string>

using namespace std;

const int MAX_OUTPUT_COUNT = 5;
const unsigned int EMPLOYEE_NUM_BOUND = 22000000;
const unsigned int EMPLOYEE_NUM_CORRECTION = 100000000;

enum class CmdType
{
    ADD,
    DEL,
    SCH,
    MOD
};

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

enum class SearchBy
{
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
    CERTI_LEVEL
};

enum class ModOption
{
    NAME,
    CAREER_LEVEL,
    PHONE_NUMBER,
    BIRTHDAY,
    CERTI_LEVEL
};

struct Birthday
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct EmployeeInformation
{
    unsigned int employeeNumber;
    string firstName;
    string lastName;
    CareerLevel careerLevel;
    unsigned int midPhoneNumber;
    unsigned int lastPhoneNumber;
    Birthday birthday;
    CertiLevel certiLevel;
};

struct ProcessResult
{
    vector<string> PrintRecord;
    unsigned int numOfRecord;
};
