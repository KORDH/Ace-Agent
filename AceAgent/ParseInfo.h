#pragma once
#include "EmployeeInformation.h"
#include "SelectType.h"

enum class Command
{
    INVALID,
    ADD,
    DEL,
    SCH,
    MOD,
};

class ParseInfo
{
public:
    ParseInfo()
    {
        command = Command::INVALID;
        isDetailPrint = false;
        searchType = SelectType::NONE;
        modifyType = SelectType::NONE;
    };

public:
    Command command;
    bool isDetailPrint;
    SelectType searchType;
    SelectType modifyType;
    EmployeeInformation employee{ 0, "               ", "               ", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE };;
    EmployeeInformation modifyEmployee{ 0, "               ", "               ", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE };;
};