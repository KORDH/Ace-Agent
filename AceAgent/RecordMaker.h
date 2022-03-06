#pragma once
#include "Type.h"
#include <string>
#include <vector>
#include <sstream>

class RecordMaker
{
public:
    vector<string> makeRecord(bool isDetailPrint, int searchCnt, CmdType cmdType, vector<EmployeeInformation> employeeInfoList);
};