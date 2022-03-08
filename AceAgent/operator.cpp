#include "operator.h"
#include "datamanager.h"
#include "SearchManager.h"

void
Operator::_calibrateEmployeeNumber(EmployeeInformation& employeeInfo)
{
    if (employeeInfo.employeeNumber_ < EMPLOYEE_NUM_BOUND) {
        employeeInfo.employeeNumber_ += EMPLOYEE_NUM_CORRECTION;
    }
}

void
Operator::addEmployee(EmployeeInformation employeeInfo)
{
    if (pDataManager->getEmployeeMap().find(employeeInfo.employeeNumber_) !=
        pDataManager->getEmployeeMap().end())
    {
        return;
    }

    _calibrateEmployeeNumber(employeeInfo);

    pDataManager->insertData(employeeInfo);
}

ProcessResult
Operator::delEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo)
{
    string record;
    ProcessResult result;
    vector<EmployeeInformation> list;
    
    if (selectType == SelectType::EMPLOYEE_NUMBER) {
        _calibrateEmployeeNumber(employeeInfo);
    }

    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() != 0) {
        for (auto it : list) {
            pDataManager->deleteData(it);
        }
    }

    result.printRecord = pRecordMaker->makeRecord(isDetailPrint, Command::DEL, list);

    return result;
}

ProcessResult
Operator::schEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo)
{
    string record;
    ProcessResult result;
    vector<EmployeeInformation> list;

    if (selectType == SelectType::EMPLOYEE_NUMBER) {
        _calibrateEmployeeNumber(employeeInfo);
    }
    
    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    result.numOfRecord = list.size();
    result.printRecord = pRecordMaker->makeRecord(isDetailPrint, Command::SCH, list);

    return result;

}

ProcessResult
Operator::modEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo, SelectType modOption, EmployeeInformation modEmployeeInfo)
{
    Operator* pOperator = new Operator;
    ProcessResult result;
    vector<EmployeeInformation> list;
    
    if (selectType == SelectType::EMPLOYEE_NUMBER) {
        _calibrateEmployeeNumber(employeeInfo);
    }

    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    if (list.size() != 0) {
        for (auto it : list) {
            pDataManager->modifyData(modOption, it.employeeNumber_, modEmployeeInfo);
        }
    }

    result.numOfRecord = list.size();
    result.printRecord = pRecordMaker->makeRecord(isDetailPrint, Command::MOD, list);

    return result;
}

