#pragma once
#include <map>
#include "EmployeeInformation.h"

class DataManager
{
public:
    map<unsigned int, EmployeeInformation>& getEmployeeMap() { return employeeMap; }

private:
    map<unsigned int, EmployeeInformation> employeeMap;
};