#pragma once
#include <map>
#include <vector>
#include "Type.h"

class DataManager
{
public:
    map<unsigned int, EmployeeInformation>* getMap() { return &dataMap; }

    void addEmployee(EmployeeInformation employeeInfo);
    ProcessResult* delEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo);
    ProcessResult* schEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo);
    ProcessResult* modEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo, ModOption modOption, EmployeeInformation modEmployeeInfo);

    vector<string> makeRecord(bool isDetailPrint, int searchCnt, CmdType cmdType, vector<EmployeeInformation> employeeInfoList);

private:
    map<unsigned int, EmployeeInformation> dataMap;

    multimap<string, unsigned int> firstNameMap;
    multimap<string, unsigned int> lastNameMap;

    multimap<CareerLevel, unsigned int> clMap;

    multimap<unsigned int, unsigned int> midPhoneNumMap;
    multimap<unsigned int, unsigned int> lastPhoneNumMap;
    
    multimap<unsigned int, unsigned int> yearofBirthdayMap;
    multimap<unsigned int, unsigned int> monthofBirthdayMap;
    multimap<unsigned int, unsigned int> dayofBirthdayMap;

    multimap<CertiLevel, unsigned int> certiLevelMap;
};
