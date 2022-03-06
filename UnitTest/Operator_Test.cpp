#include "gtest/gtest.h"
#include "../AceAgent/operator.cpp"
#include <iostream>

class OperatorTest : public ::testing::Test
{
public:
    Operator* setupData()
    {
        Operator* pOperator = new Operator;

        pOperator->addEmployee({ 15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, { 1977, 12, 11 }, CertiLevel::ADV });
        pOperator->addEmployee({ 17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, { 1986, 12, 03 }, CertiLevel::PRO });
        pOperator->addEmployee({ 18115040, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, { 2008, 07, 18 }, CertiLevel::ADV });
        pOperator->addEmployee({ 88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, { 1991, 10, 21 }, CertiLevel::PRO });
        pOperator->addEmployee({ 19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, { 1964, 9, 10 }, CertiLevel::PRO });
        pOperator->addEmployee({ 17111236, "VSID", "TVO", CareerLevel::CL1, 3669, 1077, { 2012, 07, 18 }, CertiLevel::PRO });
        pOperator->addEmployee({ 18117906, "TWU", "QSOLT", CareerLevel::CL4, 6672, 7186, { 2003, 04, 13 }, CertiLevel::PRO });
        pOperator->addEmployee({ 8123556, "WN", "XV", CareerLevel::CL1, 7986, 5047, { 2010, 06, 14 }, CertiLevel::PRO });
        pOperator->addEmployee({ 2117175, "SBILHUT", "LDEXRI", CareerLevel::CL4, 2814, 1699, { 1995, 07, 04 }, CertiLevel::ADV });
        pOperator->addEmployee({ 3113260, "HH", "LTUPF", CareerLevel::CL2, 5798, 5383, { 1979, 10, 18 }, CertiLevel::PRO });

        return pOperator;
    }

    bool isExistInMap(multimap<unsigned int, EmployeeInformation>& list, unsigned int employeeNum)
    {
        if (employeeNum < EMPLOYEE_NUM_BOUND)
        {
            employeeNum += EMPLOYEE_NUM_CORRECTION;
        }
        return (list.find(employeeNum) != list.end());
    }
};

TEST_F(OperatorTest, addOperatorTest) {
    Operator* pOperator = setupData();

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 05101762), false);
    EXPECT_EQ(isExistInMap(list, 11109136), false);
    EXPECT_EQ(isExistInMap(list, 11125777), false);
}

TEST_F(OperatorTest, delOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;

    employeeInfo.firstName = "TTETHU";
    employeeInfo.lastName = "JHOP";

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.firstName = "ABC";
    employeeInfo.lastName = "DEF";
    pResult = pOperator->delEmployee(false, SearchBy::NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 18115040), false);
}

TEST_F(OperatorTest, delOperatorTestbyFirstName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.firstName = "VXIHXOTH";

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::FIRST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 15123099), false);
}

TEST_F(OperatorTest, delOperatorTestbyLastName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.lastName = "LVARW";

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::LAST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 88114052), false);
}

TEST_F(OperatorTest, delOperatorTestbyCl) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.careerLevel = CareerLevel::CL4;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::CAREER_LEVEL, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
}

TEST_F(OperatorTest, delOperatorTestbyPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.midPhoneNumber = 4528;
    employeeInfo.lastPhoneNumber = 3059;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);

    EXPECT_EQ(isExistInMap(list, 88114052), false);
}

TEST_F(OperatorTest, delOperatorTestbyMidPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.midPhoneNumber = 4528;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::MID_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);

    EXPECT_EQ(isExistInMap(list, 88114052), false);
}

TEST_F(OperatorTest, delOperatorTestbyLastPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.lastPhoneNumber = 6122;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::LAST_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 17112609), false);
}

TEST_F(OperatorTest, delOperatorTestbyBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday = { 1964, 9, 10 };

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);

    EXPECT_EQ(isExistInMap(list, 19129568), false);
}

TEST_F(OperatorTest, delOperatorTestbyYearOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.year = 1986;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::YEAR_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 17112609), false);
}

TEST_F(OperatorTest, delOperatorTestbyMonthOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.month = 12;

    ProcessResult* pResult = pOperator ->delEmployee(false, SearchBy::MONTH_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 2);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);

    EXPECT_EQ(isExistInMap(list, 15123099), false);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
}

TEST_F(OperatorTest, delOperatorTestbyDayOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.day = 10;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::DAY_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);

    EXPECT_EQ(isExistInMap(list, 19129568), false);
}

TEST_F(OperatorTest, delOperatorTestbyCertiLevel) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.certiLevel = CertiLevel::PRO;

    ProcessResult* pResult = pOperator->delEmployee(false, SearchBy::CERTI_LEVEL, employeeInfo);

    multimap<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeNumberMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), false);
}

TEST_F(OperatorTest, schOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.firstName = "WN";
    employeeInfo.lastName = "XV";

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.firstName = "VCUHLE";
    employeeInfo.lastName = "HMU";

    pResult = pOperator->schEmployee(false, SearchBy::NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyFirstName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.firstName = "SBILHUT";

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::FIRST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.firstName = "VCUHLE";

    pResult = pOperator->schEmployee(false, SearchBy::FIRST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyLastName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.lastName = "HMEF";

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::LAST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.lastName = "MHU";

    pResult = pOperator->schEmployee(false, SearchBy::LAST_NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyCl) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.careerLevel = CareerLevel::CL2;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::CAREER_LEVEL, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 2);

    employeeInfo.careerLevel = CareerLevel::CL4;

    pResult = pOperator->schEmployee(false, SearchBy::CAREER_LEVEL, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 4);
}

TEST_F(OperatorTest, schOperatorTestbyPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.midPhoneNumber = 5645;
    employeeInfo.lastPhoneNumber = 6122;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.midPhoneNumber = 1234;
    employeeInfo.lastPhoneNumber = 5678;

    pResult = pOperator->schEmployee(false, SearchBy::PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyMidPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.midPhoneNumber = 6672;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::MID_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.midPhoneNumber = 1234;

    pResult = pOperator->schEmployee(false, SearchBy::MID_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyLastPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.lastPhoneNumber = 9521;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::LAST_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.midPhoneNumber = 1478;

    pResult = pOperator->schEmployee(false, SearchBy::LAST_PHONE_NUMBER, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday = { 2003, 04, 13 };

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.birthday = { 1999, 10, 01 };

    pResult = pOperator->schEmployee(false, SearchBy::BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyYearOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.year = 1995;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::YEAR_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.birthday.year = 2022;

    pResult = pOperator->schEmployee(false, SearchBy::YEAR_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyMonthOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.month = 12;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::MONTH_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 2);

    employeeInfo.birthday.month = 01;

    pResult = pOperator->schEmployee(false, SearchBy::MONTH_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyDayOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    employeeInfo.birthday.day = 18;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::DAY_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 3);

    employeeInfo.birthday.year = 19;

    pResult = pOperator->schEmployee(false, SearchBy::DAY_OF_BIRTHDAY, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, schOperatorTestbyCertiLevel) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;

    employeeInfo.certiLevel = CertiLevel::PRO;

    ProcessResult* pResult = pOperator->schEmployee(false, SearchBy::CERTI_LEVEL, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 7);

    employeeInfo.certiLevel = CertiLevel::EX;

    pResult = pOperator->schEmployee(false, SearchBy::CAREER_LEVEL, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, modOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation employeeInfo;
    EmployeeInformation modEmployeeInfo;

    employeeInfo.employeeNumber = 88114052;
    modEmployeeInfo.firstName = "Gildong";
    modEmployeeInfo.lastName = "Hong";

    ProcessResult* pResult = pOperator->modEmployee(false, SearchBy::EMPLOYEE_NUMBER, employeeInfo, ModOption::NAME, modEmployeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    pResult = pOperator->schEmployee(false, SearchBy::NAME, modEmployeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 1);

    employeeInfo.firstName = "NQ";
    employeeInfo.lastName = "LVARW";

    pResult = pOperator->schEmployee(false, SearchBy::NAME, employeeInfo);
    EXPECT_EQ(pResult->numOfRecord, 0);
}

TEST_F(OperatorTest, makeRecordTestbyName) {
    Operator* pOperator = setupData();
    vector<EmployeeInformation> list;

    EmployeeInformation employeeInfo;
    employeeInfo.employeeNumber = 15123099;
    employeeInfo.firstName = "VXIHXOTH";
    employeeInfo.lastName = "JHOP";
    employeeInfo.careerLevel = CareerLevel::CL3;
    employeeInfo.midPhoneNumber = 3112;
    employeeInfo.lastPhoneNumber = 2609;
    employeeInfo.birthday = { 1977, 12, 11 };
    employeeInfo.certiLevel = CertiLevel::ADV;

    list.push_back(employeeInfo);

    employeeInfo.employeeNumber = 19129568;
    employeeInfo.firstName = "SRERLALH";
    employeeInfo.lastName = "HMEF";
    employeeInfo.careerLevel = CareerLevel::CL2;
    employeeInfo.midPhoneNumber = 3091;
    employeeInfo.lastPhoneNumber = 9521;
    employeeInfo.birthday = { 1964, 9, 10 };
    employeeInfo.certiLevel = CertiLevel::PRO;

    list.push_back(employeeInfo);

    vector<string> result = pOperator->getRecordMaker()->makeRecord(true, 1, CmdType::DEL, list);

    for (auto str : result)
    {
        std::cout << str << endl;
    }


}