#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "SelectType.h"
#include "EmployeeInformation.h"

#define MAX_PRINT_DATA_COUNT		(5)

class RecordMaker
{
public:
    vector<string> makeRecord(bool isDetailPrint, Command cmdType, vector<EmployeeInformation> employeeInfoList);
};