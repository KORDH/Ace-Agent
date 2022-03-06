#pragma once
#include <map>
#include <vector>
#include "Type.h"
#include "datamanager.h"
#include "RecordMaker.h"
#include "SearchManager.h"

class IOperator
{
public:
    IOperator()
    {
        pDataManager = new DataManager;
        pSearchManager = new SearchManager;
        pRecordMaker = new RecordMaker;
    }

    ~IOperator()
    {
        if (pDataManager) { delete pDataManager; }
        if (pSearchManager) { delete pSearchManager; }
        if (pRecordMaker) { delete pRecordMaker; }
    }

    virtual void addEmployee(EmployeeInformation employeeInfo) = 0;
    virtual ProcessResult* delEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo) = 0;
    virtual ProcessResult* schEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo) = 0;
    virtual ProcessResult* modEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo, ModOption modOption, EmployeeInformation modEmployeeInfo) = 0;

    DataManager* getDataManager() { return pDataManager; }
    SearchManager* getSearchManager() { return pSearchManager; }
    RecordMaker* getRecordMaker() { return pRecordMaker; }

protected:
    DataManager* pDataManager;
    SearchManager* pSearchManager;
    RecordMaker* pRecordMaker;
};

class Operator : public IOperator
{
public:
    Operator() : IOperator() {}

    void addEmployee(EmployeeInformation employeeInfo);

    ProcessResult* delEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo);
    ProcessResult* schEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo);
    ProcessResult* modEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo, ModOption modOption, EmployeeInformation modEmployeeInfo);

    void insertData(EmployeeInformation employeeInfo);
    void deleteData(EmployeeInformation employeeInfo);
};

class ModOperator : public Operator
{
public:
    void modData(ModOption modOption, EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
    void _updateMap(EmployeeInformation oldEmployeeInfo, EmployeeInformation modEmployeeInfo);

    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo) {}
};

class NameModOperator : public ModOperator
{
public:
    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
};

class CareerLevelModOperator : public ModOperator
{
public:
    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
};

class PhoneNumModOperator : public ModOperator
{
public:
    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
};

class BirthdayModOperator : public ModOperator
{
public:
    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
};

class CertiLevelModOperator : public ModOperator
{
public:
    void _constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo);
};
