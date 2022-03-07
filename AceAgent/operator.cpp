#include "operator.h"
#include "datamanager.h"
#include "SearchManager.h"

void
Operator::insertData(EmployeeInformation employeeInfo)
{
    unsigned int employeeNumber = employeeInfo.employeeNumber_;

    pDataManager->getEmployeeMap().insert(make_pair(employeeInfo.employeeNumber_, employeeInfo));
}

void
Operator::deleteData(EmployeeInformation employeeInfo)
{
    pDataManager->getEmployeeMap().erase(employeeInfo.employeeNumber_);
}

void
Operator::addEmployee(EmployeeInformation employeeInfo)
{
    if (pDataManager->getEmployeeMap().find(employeeInfo.employeeNumber_) !=
        pDataManager->getEmployeeMap().end())
    {
        return;
    }

    if (employeeInfo.employeeNumber_ < EMPLOYEE_NUM_BOUND)
    {
        employeeInfo.employeeNumber_ += EMPLOYEE_NUM_CORRECTION;
    }

    insertData(employeeInfo);
}

ProcessResult
Operator::delEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo)
{
    string record;
    ProcessResult result;
    vector<EmployeeInformation> list;
    
    if (selectType == SelectType::EMPLOYEE_NUMBER && employeeInfo.employeeNumber_ < EMPLOYEE_NUM_BOUND)
    {
        employeeInfo.employeeNumber_ += EMPLOYEE_NUM_CORRECTION;
    }

    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() != 0)
    {
        for (auto it : list)
        {
            deleteData(it);
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

    if (selectType == SelectType::EMPLOYEE_NUMBER && employeeInfo.employeeNumber_ < EMPLOYEE_NUM_BOUND)
    {
        employeeInfo.employeeNumber_ += EMPLOYEE_NUM_CORRECTION;
    }
    
    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    result.numOfRecord = list.size();

    result.printRecord = pRecordMaker->makeRecord(isDetailPrint, Command::DEL, list);

    return result;

}

ProcessResult
Operator::modEmployee(bool isDetailPrint, SelectType selectType, EmployeeInformation employeeInfo, SelectType modOption, EmployeeInformation modEmployeeInfo)
{
    Operator* pOperator = new Operator;
    ProcessResult result;
    vector<EmployeeInformation> list;
    
    if (selectType == SelectType::EMPLOYEE_NUMBER && employeeInfo.employeeNumber_ < EMPLOYEE_NUM_BOUND)
    {
        employeeInfo.employeeNumber_ += EMPLOYEE_NUM_CORRECTION;
    }

    list = pSearchManager->SearchEmployeeData(pDataManager, selectType, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() != 0)
    {
        for (auto it : list)
        {
            pOperator->_modData(pDataManager, modOption, it.employeeNumber_, modEmployeeInfo);
        }
    }

    result.printRecord = pRecordMaker->makeRecord(isDetailPrint, Command::MOD, list);

    return result;
}

void
Operator::_modData(DataManager* pDataManager, SelectType modOption, unsigned int employeeNumber, EmployeeInformation modEmployeeInfo)
{
    EmployeeInformation* employeeInfoInMap = &pDataManager->getEmployeeMap().find(employeeNumber)->second;

    switch (modOption)
    {
    case SelectType::FULL_NAME:
        employeeInfoInMap->setName(modEmployeeInfo.name_);
        break;

    case SelectType::CAREER_LEVEL:
        employeeInfoInMap->setCareerLevel(modEmployeeInfo.careerLevel_);
        break;

    case SelectType::CERTI_LEVEL:
        employeeInfoInMap->setCertiLevel(modEmployeeInfo.certiLevel_);
        break;

    case SelectType::FULL_PHONE_NUMBER:
        employeeInfoInMap->setPhoneNumber(modEmployeeInfo.phoneNumber_);
        break;

    case SelectType::FULL_BIRTHDAY:
        employeeInfoInMap->setBirthday(modEmployeeInfo.birthday_);
        break;
    }
}
