#pragma once
#include <map>
#include <vector>
#include "SelectType.h"
#include "ProcessResult.h"
#include "datamanager.h"
#include "RecordMaker.h"
#include "SearchManager.h"
#include "EmployeeInformation.h"
#include "IDataManager.h"

class Operator : public IDataManager
{
public:
    Operator()
    {
        pDataManager = new DataManager;
        pSearchManager = new SearchManager;
        pRecordMaker = new RecordMaker;
    }

    ~Operator()
    {
        if (pDataManager) { delete pDataManager; }
        if (pSearchManager) { delete pSearchManager; }
        if (pRecordMaker) { delete pRecordMaker; }
    }

    DataManager* getDataManager() { return pDataManager; }
    SearchManager* getSearchManager() { return pSearchManager; }
    RecordMaker* getRecordMaker() { return pRecordMaker; }

    void addEmployee(EmployeeInformation employeeInfo);
    ProcessResult delEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo);
    ProcessResult schEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo);
    ProcessResult modEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo, SelectType modOption, EmployeeInformation modEmployeeInfo);
    void _calibrateEmployeeNumber(EmployeeInformation& employeeInfo);

private:
    DataManager* pDataManager;
    SearchManager* pSearchManager;
    RecordMaker* pRecordMaker;
};

