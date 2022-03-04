#pragma once
#include "EmployeeInformation.h"

class ParseInfo
{
public:
    ParseInfo()
    {
        command = Command::INVALID;
        isDetailPrint = false;
        searchType = SelectType::INVALID;
        modifyType = SelectType::INVALID;
        employee = { 0, {"               ", "               "},
                   CareerLevel::INVALID, {0, 0}, {0, 0, 0}, CertiLevel::INVALID };
        modifyEmployee = { 0, {"               ", "               "},
                         CareerLevel::INVALID, {0, 0}, {0, 0, 0}, CertiLevel::INVALID };
    };

public:
    Command command;
    bool isDetailPrint;
    SelectType searchType;
    SelectType modifyType;
    EmployeeInformation employee;
    EmployeeInformation modifyEmployee;
};