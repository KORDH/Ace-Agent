#include "operator.h"
#include "datamanager.h"
#include "SearchManager.h"

void
Operator::insertData(EmployeeInformation employeeInfo)
{
    pDataManager->getEmployeeNumberMap().insert(make_pair(employeeInfo.employeeNumber, employeeInfo));
    pDataManager->getFirstNameMap().insert(make_pair(employeeInfo.firstName, employeeInfo));
    pDataManager->getLastNameMap().insert(make_pair(employeeInfo.lastName, employeeInfo));
    pDataManager->getCareerLevelMap().insert(make_pair((unsigned int)(employeeInfo.careerLevel), employeeInfo));
    pDataManager->getMidPhoneNumberMap().insert(make_pair(to_string(employeeInfo.midPhoneNumber), employeeInfo));
    pDataManager->getLastPhoneNumberMap().insert(make_pair(to_string(employeeInfo.lastPhoneNumber), employeeInfo));
    pDataManager->getYearOfBirthdayMap().insert(make_pair(employeeInfo.birthday.year, employeeInfo));
    pDataManager->getMonthOfBirthdayMap().insert(make_pair(employeeInfo.birthday.month, employeeInfo));
    pDataManager->getDayOfBirthdayMap().insert(make_pair(employeeInfo.birthday.day, employeeInfo));
    pDataManager->getCertiLevelMap().insert(make_pair((unsigned int)(employeeInfo.certiLevel), employeeInfo));
}

void
Operator::deleteData(EmployeeInformation employeeInfo)
{
    pDataManager->getEmployeeNumberMap().erase(employeeInfo.employeeNumber);
    pDataManager->getFirstNameMap().erase(employeeInfo.firstName);
    pDataManager->getLastNameMap().erase(employeeInfo.lastName);
    pDataManager->getCareerLevelMap().erase((unsigned int)(employeeInfo.careerLevel));
    pDataManager->getMidPhoneNumberMap().erase(to_string(employeeInfo.midPhoneNumber));
    pDataManager->getLastPhoneNumberMap().erase(to_string(employeeInfo.lastPhoneNumber));
    pDataManager->getYearOfBirthdayMap().erase(employeeInfo.birthday.year);
    pDataManager->getMonthOfBirthdayMap().erase(employeeInfo.birthday.month);
    pDataManager->getDayOfBirthdayMap().erase(employeeInfo.birthday.day);
    pDataManager->getCertiLevelMap().erase((unsigned int)(employeeInfo.certiLevel));
}

void
Operator::addEmployee(EmployeeInformation employeeInfo)
{
    if (pDataManager->getEmployeeNumberMap().find(employeeInfo.employeeNumber) !=
        pDataManager->getEmployeeNumberMap().end())
    {
        return;
    }

    if (employeeInfo.employeeNumber < EMPLOYEE_NUM_BOUND)
    {
        employeeInfo.employeeNumber += EMPLOYEE_NUM_CORRECTION;
    }

    insertData(employeeInfo);
}

ProcessResult*
Operator::delEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo)
{
    string record;
    ProcessResult result;
    vector<EmployeeInformation> list = pSearchManager->SearchEmployeeData(pDataManager, searchBy, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() == 0)
    {
        result.PrintRecord.clear();

        return &result;
    }

    for (auto it : list)
    {
        deleteData(employeeInfo);
    }

    result.PrintRecord = pRecordMaker->makeRecord(isDetailPrint, list.size(), CmdType::DEL, list);

    return &result;
}

ProcessResult*
Operator::schEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo)
{
    string record;
    ProcessResult result;
    vector<EmployeeInformation> list = pSearchManager->SearchEmployeeData(pDataManager, searchBy, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() == 0)
    {
        result.PrintRecord.clear();

        return &result;
    }

    result.PrintRecord = pRecordMaker->makeRecord(isDetailPrint, list.size(), CmdType::DEL, list);

    return &result;
}

ProcessResult*
Operator::modEmployee(bool isDetailPrint, SearchBy searchBy, EmployeeInformation employeeInfo, ModOption modOption, EmployeeInformation modEmployeeInfo)
{
    ModOperator* pOperator = new ModOperator;
    ProcessResult result;
    vector<EmployeeInformation> list = pSearchManager->SearchEmployeeData(pDataManager, searchBy, employeeInfo);

    result.numOfRecord = list.size();

    if (list.size() == 0)
    {
        return &result;
    }

    for (auto it : list)
    {
        pOperator->modData(modOption, it, &modEmployeeInfo);
    }

    result.PrintRecord = pRecordMaker->makeRecord(isDetailPrint, list.size(), CmdType::MOD, list);

    return &result;
}

void
ModOperator::modData(ModOption modOption, EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    ModOperator* pOperator;

    switch (modOption)
    {
    case ModOption::NAME:
        pOperator = new NameModOperator;
        break;

    case ModOption::CAREER_LEVEL:
        pOperator = new CareerLevelModOperator;
        break;

    case ModOption::PHONE_NUMBER:
        pOperator = new PhoneNumModOperator;
        break;

    case ModOption::BIRTHDAY:
        pOperator = new BirthdayModOperator;
        break;

    case ModOption::CERTI_LEVEL:
        pOperator = new CertiLevelModOperator;
        break;
    }

    pOperator->_constructModInfo(employeeInfo, pModEmployeeInfo);
    _updateMap(employeeInfo, *pModEmployeeInfo);
}

void 
NameModOperator::_constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    string modFirstName = pModEmployeeInfo->firstName;
    string modLastName = pModEmployeeInfo->lastName;

    memcpy(pModEmployeeInfo, &employeeInfo, sizeof(EmployeeInformation));
    pModEmployeeInfo->firstName = modFirstName;
    pModEmployeeInfo->lastName = modLastName;
}

void
CareerLevelModOperator::_constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    CareerLevel modCareerLevel = pModEmployeeInfo->careerLevel;

    memcpy(pModEmployeeInfo, &employeeInfo, sizeof(EmployeeInformation));
    pModEmployeeInfo->careerLevel = modCareerLevel;
}

void
PhoneNumModOperator::_constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    unsigned int midPhoneNumber = pModEmployeeInfo->midPhoneNumber;
    unsigned int lastPhoneNumber = pModEmployeeInfo->lastPhoneNumber;

    memcpy(pModEmployeeInfo, &employeeInfo, sizeof(EmployeeInformation));
    pModEmployeeInfo->midPhoneNumber = midPhoneNumber;
    pModEmployeeInfo->lastPhoneNumber = lastPhoneNumber;
}

void
BirthdayModOperator::_constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    unsigned int yearOfBirth = pModEmployeeInfo->birthday.year;
    unsigned int monthOfBirth = pModEmployeeInfo->birthday.month;
    unsigned int dayOfBirth = pModEmployeeInfo->birthday.day;

    memcpy(pModEmployeeInfo, &employeeInfo, sizeof(EmployeeInformation));
    pModEmployeeInfo->birthday.year = yearOfBirth;
    pModEmployeeInfo->birthday.month = monthOfBirth;
    pModEmployeeInfo->birthday.day = dayOfBirth;
}

void
CertiLevelModOperator::_constructModInfo(EmployeeInformation employeeInfo, EmployeeInformation* pModEmployeeInfo)
{
    CertiLevel certiLevel = pModEmployeeInfo->certiLevel;

    memcpy(pModEmployeeInfo, &employeeInfo, sizeof(EmployeeInformation));
    pModEmployeeInfo->certiLevel = certiLevel;
}

void
ModOperator::_updateMap(EmployeeInformation oldEmployeeInfo, EmployeeInformation modEmployeeInfo)
{
    multimap<unsigned int, EmployeeInformation> employeeNumMap = pDataManager->getEmployeeNumberMap();
    multimap<unsigned int, EmployeeInformation> careerLevelMap = pDataManager->getCareerLevelMap();
    multimap<unsigned int, EmployeeInformation> yearOfBirthMap = pDataManager->getYearOfBirthdayMap();
    multimap<unsigned int, EmployeeInformation> monthOfBirthMap = pDataManager->getMonthOfBirthdayMap();
    multimap<unsigned int, EmployeeInformation> dayOfBirthMap = pDataManager->getDayOfBirthdayMap();
    multimap<unsigned int, EmployeeInformation> certiLevelMap = pDataManager->getCertiLevelMap();
    multimap<string, EmployeeInformation> firstNameMap = pDataManager->getFirstNameMap();
    multimap<string, EmployeeInformation> lastNameMap = pDataManager->getLastNameMap();
    multimap<string, EmployeeInformation> midPhoneNumMap = pDataManager->getMidPhoneNumberMap();
    multimap<string, EmployeeInformation> lastPhoneNumMap = pDataManager->getLastPhoneNumberMap();

    employeeNumMap.find(oldEmployeeInfo.employeeNumber)->second = modEmployeeInfo;
    careerLevelMap.find((unsigned int)oldEmployeeInfo.careerLevel)->second = modEmployeeInfo;
    yearOfBirthMap.find(oldEmployeeInfo.birthday.year)->second = modEmployeeInfo;
    monthOfBirthMap.find(oldEmployeeInfo.birthday.month)->second = modEmployeeInfo;
    dayOfBirthMap.find(oldEmployeeInfo.birthday.day)->second = modEmployeeInfo;
    certiLevelMap.find((unsigned int)oldEmployeeInfo.certiLevel)->second = modEmployeeInfo;
    firstNameMap.find(oldEmployeeInfo.firstName)->second = modEmployeeInfo;
    lastNameMap.find(oldEmployeeInfo.lastName)->second = modEmployeeInfo;
    midPhoneNumMap.find(to_string(oldEmployeeInfo.midPhoneNumber))->second = modEmployeeInfo;
    lastPhoneNumMap.find(to_string(oldEmployeeInfo.lastPhoneNumber))->second = modEmployeeInfo;
}
