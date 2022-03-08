#pragma once
#include <map>
#include "EmployeeInformation.h"
#include "SelectType.h"

class DataManager
{
public:
    map<unsigned int, EmployeeInformation>& getEmployeeMap() { return employeeMap; }
    void insertData(EmployeeInformation employeeInfo);
    void deleteData(EmployeeInformation employeeInfo);
    void modifyData(SelectType modOption, unsigned int employeeNumber, EmployeeInformation modEmployeeInfo);

private:
    map<unsigned int, EmployeeInformation> employeeMap;
};