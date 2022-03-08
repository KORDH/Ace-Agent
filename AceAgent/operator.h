#pragma once
#include <map>
#include <vector>
#include "SelectType.h"
#include "ProcessResult.h"
#include "datamanager.h"
#include "RecordMaker.h"
#include "SearchManager.h"
#include "EmployeeInformation.h"
#include "IOperator.h"

class Operator : public IOperator
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
    ProcessResult deleteEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo);
    ProcessResult searchEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo);
    ProcessResult modifyEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo, SelectType modOption, EmployeeInformation modEmployeeInfo);
    void _modData(DataManager* pDataManager, SelectType modOption, unsigned int employeeNumber, EmployeeInformation modEmployeeInfo);

    void insertData(EmployeeInformation employeeInfo);
    void deleteData(EmployeeInformation employeeInfo);

private:
    DataManager* pDataManager;
    SearchManager* pSearchManager;
    RecordMaker* pRecordMaker;
};

