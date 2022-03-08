#include "datamanager.h"

void
DataManager::insertData(EmployeeInformation employeeInfo)
{
    unsigned int employeeNumber = employeeInfo.employeeNumber_;

    employeeMap.insert(make_pair(employeeInfo.employeeNumber_, employeeInfo));
}

void
DataManager::deleteData(EmployeeInformation employeeInfo)
{
    employeeMap.erase(employeeInfo.employeeNumber_);
}

void
DataManager::modifyData(SelectType modOption, unsigned int employeeNumber, EmployeeInformation modEmployeeInfo)
{
    EmployeeInformation* employeeInfoInMap = &employeeMap.find(employeeNumber)->second;

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