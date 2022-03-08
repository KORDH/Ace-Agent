#pragma once
#include <vector>
#include <string>
#include "ParseInfo.h"

class CommandParser
{
public:
    void parseCommandLine(string commandLine, ParseInfo& parseInfo);

private:
    void InsertCommandLine(string commandLine);

    void setParseInfo(ParseInfo& parseInfo);
    void setCommand(ParseInfo& parseInfo);
    void setIsDetailPrint(ParseInfo& parseInfo);
    void setSearchType(ParseInfo& parseInfo);
    void setModifyType(ParseInfo& parseInfo);
    void setEmployee(ParseInfo& parseInfo);
    void setModifyEmployee(ParseInfo& parseInfo);

    void setEmployeeForAdd(ParseInfo& parseInfo);
    void setEmployeeForSearch(ParseInfo& parseInfo);    
    CareerLevel transCareerLevel(string CareerLevelString);
    PhoneNumber transPhoneNumber(string phoneNumberString);
    Name transName(string fullName);
    Birthday transBirthday(string birthDayString);
    CertiLevel transCertiLevel(string certiString);    

    int CheckEmployeeNumber(int employeeNumber);
    void CheckName(string fullName);
private:
    vector<string> tokens;

    static constexpr unsigned int COMMAND = 0;
    static constexpr unsigned int PRINT_OPTION = 1;
    static constexpr unsigned int SEARCH_OPTION = 2;
    static constexpr unsigned int DEAD_OPTION = 3;

    static constexpr unsigned int EMPLOYEE_NUMBER = 4;
    static constexpr unsigned int EMPLOYEE_NAME = 5;
    static constexpr unsigned int EMPLOYEE_CAREER_LEVEL = 6;
    static constexpr unsigned int EMPLOYEE_PHONE_NUMBER = 7;
    static constexpr unsigned int EMPLOYEE_BIRTYDAY = 8;
    static constexpr unsigned int EMPLOYEE_CERTI = 9;

    static constexpr unsigned int SEARCH_CATEGORY = 4;
    static constexpr unsigned int SEARCH_VALUE = 5;
    static constexpr unsigned int MODIFY_CATEGORY = 6;
    static constexpr unsigned int MODIFY_VALUE = 7;
};