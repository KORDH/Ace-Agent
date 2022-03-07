#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "SelectType.h"
#include "EmployeeInformation.h"

class RecordMaker
{
public:
    vector<string> makeRecord(bool isDetailPrint, Command cmdType, vector<EmployeeInformation> employeeInfoList);
};