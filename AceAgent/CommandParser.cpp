#include <iostream>
#include <sstream>
#include "CommandParser.h"

void 
CommandParser::parseCommandLine(string commandLine, ParseInfo& parseInfo) 
{
    InsertCommandLine(commandLine);
    setParseInfo(parseInfo);
}

void 
CommandParser::InsertCommandLine(string commandLine)
{
    stringstream commandStream(commandLine);
    string token;

    while (getline(commandStream, token, ','))
    {
        tokens.push_back(token);
    }
}

void 
CommandParser::setParseInfo(ParseInfo& parseInfo)
{
    setCommand(parseInfo);

    setIsDetailPrint(parseInfo);
    setSearchType(parseInfo);
    setModifyType(parseInfo);
    setEmployee(parseInfo);
    setModifyEmployee(parseInfo);
}

void 
CommandParser::setCommand(ParseInfo& parseInfo)
{
    Command command;

    if (tokens[COMMAND] == "ADD") command = Command::ADD;
    else if (tokens[COMMAND] == "MOD") command = Command::MOD;
    else if (tokens[COMMAND] == "SCH") command = Command::SCH;
    else if (tokens[COMMAND] == "DEL") command = Command::DEL;
    else command = Command::INVALID;

    parseInfo.command = command;
}

void 
CommandParser::setIsDetailPrint(ParseInfo& parseInfo)
{
    bool isPrint = false;

    if (tokens[PRINT_OPTION] == "-p") isPrint = true;

    parseInfo.isDetailPrint = isPrint;
}

void 
CommandParser::setSearchType(ParseInfo& parseInfo)
{
    SelectType searchType = SelectType::INVALID;

    if (tokens[COMMAND] == "ADD")
    {
        searchType = SelectType::INVALID;
    }
    else
    {
        if (tokens[SEARCH_CATEGORY] == "employeeNum") searchType = SelectType::EMPLOYEE_NUMBER;
        else if (tokens[SEARCH_CATEGORY] == "name" && tokens[SEARCH_OPTION] == "-f")   searchType = SelectType::FIRST_NAME;
        else if (tokens[SEARCH_CATEGORY] == "name" && tokens[SEARCH_OPTION] == "-l")   searchType = SelectType::LAST_NAME;
        else if (tokens[SEARCH_CATEGORY] == "name")   searchType = SelectType::NAME;
        else if (tokens[SEARCH_CATEGORY] == "cl")     searchType = SelectType::CAREER_LEVEL;
        else if (tokens[SEARCH_CATEGORY] == "phoneNum" && tokens[SEARCH_OPTION] == "-m") searchType = SelectType::MID_PHONE_NUMBER;
        else if (tokens[SEARCH_CATEGORY] == "phoneNum" && tokens[SEARCH_OPTION] == "-l") searchType = SelectType::LAST_PHONE_NUMBER;
        else if (tokens[SEARCH_CATEGORY] == "phoneNum") searchType = SelectType::PHONE_NUMBER;
        else if (tokens[SEARCH_CATEGORY] == "birthday" && tokens[SEARCH_OPTION] == "-y") searchType = SelectType::YEAR_OF_BIRTHDAY;
        else if (tokens[SEARCH_CATEGORY] == "birthday" && tokens[SEARCH_OPTION] == "-m") searchType = SelectType::MONTH_OF_BIRTHDAY;
        else if (tokens[SEARCH_CATEGORY] == "birthday" && tokens[SEARCH_OPTION] == "-d") searchType = SelectType::DAY_OF_BIRTHDAY;
        else if (tokens[SEARCH_CATEGORY] == "birthday") searchType = SelectType::BIRTHDAY;
        else if (tokens[SEARCH_CATEGORY] == "certi") searchType = SelectType::CERTI_LEVEL;
        else searchType = SelectType::INVALID;
    }

    parseInfo.searchType = searchType;
}

void
CommandParser::setModifyType(ParseInfo& parseInfo)
{
    SelectType modifyType = SelectType::INVALID;

    if ((tokens[COMMAND] == "MOD"))
    {
        if (tokens[MODIFY_CATEGORY] == "employeeNum") modifyType = SelectType::EMPLOYEE_NUMBER;
        else if (tokens[MODIFY_CATEGORY] == "name")   modifyType = SelectType::NAME;
        else if (tokens[MODIFY_CATEGORY] == "cl")     modifyType = SelectType::CAREER_LEVEL;
        else if (tokens[MODIFY_CATEGORY] == "phoneNum") modifyType = SelectType::PHONE_NUMBER;
        else if (tokens[MODIFY_CATEGORY] == "birthday") modifyType = SelectType::BIRTHDAY;
        else if (tokens[MODIFY_CATEGORY] == "certi") modifyType = SelectType::CERTI_LEVEL;
        else modifyType = SelectType::INVALID;
    }

    parseInfo.modifyType = modifyType;
}

void 
CommandParser::setEmployee(ParseInfo& parseInfo)
{
    if (tokens[COMMAND] == "ADD") setEmployeeForAdd(parseInfo);
    else setEmployeeForSearch(parseInfo);
}

void
CommandParser::setEmployeeForSearch(ParseInfo& parseInfo)
{
    switch (parseInfo.searchType)
    {
    case SelectType::EMPLOYEE_NUMBER:   parseInfo.employee.employeeNumber = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::NAME:              parseInfo.employee.name = transName(tokens[SEARCH_VALUE]); break;
    case SelectType::FIRST_NAME:        parseInfo.employee.name.first = tokens[SEARCH_VALUE]; break;
    case SelectType::LAST_NAME:         parseInfo.employee.name.last = tokens[SEARCH_VALUE]; break;
    case SelectType::CAREER_LEVEL:      parseInfo.employee.careerLevel = transCareerLevel(tokens[SEARCH_VALUE]); break;
    case SelectType::PHONE_NUMBER:      parseInfo.employee.phoneNumber = transPhoneNumber(tokens[SEARCH_VALUE]); break;
    case SelectType::MID_PHONE_NUMBER:  parseInfo.employee.phoneNumber.mid = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::LAST_PHONE_NUMBER: parseInfo.employee.phoneNumber.last = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::BIRTHDAY:          parseInfo.employee.birthday = transBirthday(tokens[SEARCH_VALUE]); break;
    case SelectType::YEAR_OF_BIRTHDAY:  parseInfo.employee.birthday.year = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::MONTH_OF_BIRTHDAY: parseInfo.employee.birthday.month = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::DAY_OF_BIRTHDAY:   parseInfo.employee.birthday.day = stoi(tokens[SEARCH_VALUE]); break;
    case SelectType::CERTI_LEVEL:       parseInfo.employee.certiLevel = transCertiLevel(tokens[SEARCH_VALUE]); break;
    }

    return;
}

void
CommandParser::setEmployeeForAdd(ParseInfo& parseInfo)
{
    parseInfo.employee.employeeNumber = stoi(tokens[EMPLOYEE_NUMBER]);
    parseInfo.employee.name = transName(tokens[EMPLOYEE_NAME]);
    parseInfo.employee.careerLevel = transCareerLevel(tokens[EMPLOYEE_CAREER_LEVEL]);
    parseInfo.employee.phoneNumber = transPhoneNumber(tokens[EMPLOYEE_PHONE_NUMBER]);
    parseInfo.employee.birthday = transBirthday(tokens[EMPLOYEE_BIRTYDAY]);
    parseInfo.employee.certiLevel = transCertiLevel(tokens[EMPLOYEE_CERTI]);
}

CertiLevel
CommandParser::transCertiLevel(string stringCertiLevel)
{
    CertiLevel careerLevel = CertiLevel::INVALID;

    if (stringCertiLevel == "ADV") careerLevel = CertiLevel::ADV;
    else if (stringCertiLevel == "PRO") careerLevel = CertiLevel::PRO;
    else if (stringCertiLevel == "EX") careerLevel = CertiLevel::EX;

    return careerLevel;
}

Birthday
CommandParser::transBirthday(string stringBirthday)
{
    Birthday birthday{ (unsigned int)stoi(stringBirthday.substr(0, 4)),
                       (unsigned int)stoi(stringBirthday.substr(4, 2)),
                       (unsigned int)stoi(stringBirthday.substr(6, 2)) };

    return birthday;
}

Name
CommandParser::transName(string fullName)
{
    stringstream commandStream(fullName);
    string token;
    vector<string> names;

    while (getline(commandStream, token, ' '))
    {
        names.push_back(token);
    }
    Name name{ names[0], names[1] };

    return name;
}

PhoneNumber
CommandParser::transPhoneNumber(string phoneNumberString)
{
    stringstream commandStream(phoneNumberString);
    string token;
    vector<unsigned int> number;

    while (getline(commandStream, token, '-'))
    {
        number.push_back(stoi(token));
    }
    PhoneNumber phoneNumber{ number[1], number[2] };

    return phoneNumber;
}

CareerLevel
CommandParser::transCareerLevel(string careerLevelString)
{
    CareerLevel careerLevel = CareerLevel::INVALID;

    if (careerLevelString == "CL1") careerLevel = CareerLevel::CL1;
    else if (careerLevelString == "CL2") careerLevel = CareerLevel::CL2;
    else if (careerLevelString == "CL3") careerLevel = CareerLevel::CL3;
    else if (careerLevelString == "CL4") careerLevel = CareerLevel::CL4;

    return careerLevel;
}

void 
CommandParser::setModifyEmployee(ParseInfo& parseInfo)
{
    if ((tokens[COMMAND] != "MOD")) return;

    switch (parseInfo.modifyType)
    {
    case SelectType::EMPLOYEE_NUMBER:   parseInfo.modifyEmployee.employeeNumber = stoi(tokens[MODIFY_VALUE]); break;
    case SelectType::NAME:              parseInfo.modifyEmployee.name = transName(tokens[MODIFY_VALUE]); break;
    case SelectType::CAREER_LEVEL:      parseInfo.modifyEmployee.careerLevel = transCareerLevel(tokens[MODIFY_VALUE]); break;
    case SelectType::PHONE_NUMBER:      parseInfo.modifyEmployee.phoneNumber = transPhoneNumber(tokens[MODIFY_VALUE]); break;
    case SelectType::BIRTHDAY:          parseInfo.modifyEmployee.birthday = transBirthday(tokens[MODIFY_VALUE]); break;
    case SelectType::CERTI_LEVEL:       parseInfo.modifyEmployee.certiLevel = transCertiLevel(tokens[MODIFY_VALUE]); break;
    }

    return;
}