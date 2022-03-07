#include "gtest/gtest.h"
#include "../AceAgent/operator.cpp"
#include "../AceAgent/RecordMaker.cpp"
#include <iostream>

class OperatorTest : public ::testing::Test
{
public:
    Operator* setupData()
    {
        Operator* pOperator = new Operator;

        pOperator->addEmployee(*(new EmployeeInformation(15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, 1977, 12, 11, CertiLevel::ADV)));
        pOperator->addEmployee(*(new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(18115040, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, 2008, 07, 18, CertiLevel::ADV)));
        pOperator->addEmployee(*(new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(17111236, "VSID", "TVO", CareerLevel::CL1, 3669, 1077, 2012, 07, 18, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(18117906, "TWU", "QSOLT", CareerLevel::CL4, 6672, 7186, 2003, 04, 13, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(8123556, "WN", "XV", CareerLevel::CL1, 7986, 5047, 2010, 06, 14, CertiLevel::PRO)));
        pOperator->addEmployee(*(new EmployeeInformation(2117175, "SBILHUT", "LDEXRI", CareerLevel::CL4, 2814, 1699, 1995, 07, 04, CertiLevel::ADV)));
        pOperator->addEmployee(*(new EmployeeInformation(3113260, "HH", "LTUPF", CareerLevel::CL2, 5798, 5383, 1979, 10, 18, CertiLevel::PRO)));

        return pOperator;
    }

    bool isExistInMap(map<unsigned int, EmployeeInformation>& list, unsigned int employeeNum)
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

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);
}


TEST_F(OperatorTest, delOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(18115040, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, 2008, 07, 18, CertiLevel::ADV);

    ProcessResult result = pOperator->delEmployee(true, SelectType::FULL_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);

    pEmployeeInfo->name_.first = "ABC";
    pEmployeeInfo->name_.last = "DEF";
    result = pOperator->delEmployee(false, SelectType::FULL_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), false);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyFirstName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, 1977, 12, 11, CertiLevel::ADV);

    ProcessResult result = pOperator->delEmployee(true, SelectType::FIRST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), false);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyLastName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::LAST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyCl) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::CAREER_LEVEL, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 4);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 18117906), false);
    EXPECT_EQ(isExistInMap(list, 2117175), false);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::FULL_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyMidPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::MID_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyLastPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::LAST_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::FULL_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), false);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyYearOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::YEAR_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyMonthOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator ->delEmployee(true, SelectType::MONTH_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 2);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), false);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), true);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyDayOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::DAY_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), true);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), true);
    EXPECT_EQ(isExistInMap(list, 17111236), true);
    EXPECT_EQ(isExistInMap(list, 18117906), true);
    EXPECT_EQ(isExistInMap(list, 8123556), true);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), true);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, delOperatorTestbyCertiLevel) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO);

    ProcessResult result = pOperator->delEmployee(true, SelectType::CERTI_LEVEL, *pEmployeeInfo);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    map<unsigned int, EmployeeInformation> list = pOperator->getDataManager()->getEmployeeMap();

    EXPECT_EQ(isExistInMap(list, 15123099), true);
    EXPECT_EQ(isExistInMap(list, 17112609), false);
    EXPECT_EQ(isExistInMap(list, 18115040), true);
    EXPECT_EQ(isExistInMap(list, 88114052), false);
    EXPECT_EQ(isExistInMap(list, 19129568), false);
    EXPECT_EQ(isExistInMap(list, 17111236), false);
    EXPECT_EQ(isExistInMap(list, 18117906), false);
    EXPECT_EQ(isExistInMap(list, 8123556), false);
    EXPECT_EQ(isExistInMap(list, 2117175), true);
    EXPECT_EQ(isExistInMap(list, 3113260), false);

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(8123556, "WN", "XV", CareerLevel::CL1, 7986, 5047, 2010, 06, 14, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::FULL_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->name_.first = "VCUHLE";
    pEmployeeInfo->name_.last = "HMU";

    result = pOperator->schEmployee(false, SelectType::FULL_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyFirstName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(2117175, "SBILHUT", "LDEXRI", CareerLevel::CL4, 2814, 1699, 1995, 07, 04, CertiLevel::ADV);

    ProcessResult result = pOperator->schEmployee(true, SelectType::FIRST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->name_.first = "VCUHLE";

    result = pOperator->schEmployee(false, SelectType::FIRST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyLastName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::LAST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->name_.last = "MHU";

    result = pOperator->schEmployee(false, SelectType::LAST_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyCl) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::CAREER_LEVEL, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 2);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->careerLevel_ = CareerLevel::CL4;

    result = pOperator->schEmployee(false, SelectType::CAREER_LEVEL, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 4);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::FULL_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->phoneNumber_.mid = 1234;
    pEmployeeInfo->phoneNumber_.last = 5678;

    result = pOperator->schEmployee(false, SelectType::FULL_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyMidPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(18117906, "TWU", "QSOLT", CareerLevel::CL4, 6672, 7186, 2003, 04, 13, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::MID_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->phoneNumber_.mid = 1234;

    result = pOperator->schEmployee(false, SelectType::MID_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyLastPhoneNum) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::LAST_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->phoneNumber_.last = 1478;

    result = pOperator->schEmployee(false, SelectType::LAST_PHONE_NUMBER, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(18117906, "TWU", "QSOLT", CareerLevel::CL4, 6672, 7186, 2003, 04, 13, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::FULL_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->birthday_ = { 1999, 10, 01 };

    result = pOperator->schEmployee(false, SelectType::FULL_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyYearOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(2117175, "SBILHUT", "LDEXRI", CareerLevel::CL4, 2814, 1699, 1995, 07, 04, CertiLevel::ADV);

    ProcessResult result = pOperator->schEmployee(true, SelectType::YEAR_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 1);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->birthday_.year_ = 2022;

    result = pOperator->schEmployee(false, SelectType::YEAR_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyMonthOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, 1977, 12, 11, CertiLevel::ADV);

    ProcessResult result = pOperator->schEmployee(true, SelectType::MONTH_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 2);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->birthday_.month_ = 01;

    result = pOperator->schEmployee(false, SelectType::MONTH_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyDayOfBirthday) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(18115040, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, 2008, 07, 18, CertiLevel::ADV);

    ProcessResult result = pOperator->schEmployee(true, SelectType::DAY_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 3);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }
    
    pEmployeeInfo->setBirthday({ 2022, 3, 7 });

    result = pOperator->schEmployee(false, SelectType::DAY_OF_BIRTHDAY, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, schOperatorTestbyCertiLevel) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator->schEmployee(true, SelectType::CERTI_LEVEL, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 5);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->certiLevel_ = CertiLevel::EX;

    result = pOperator->schEmployee(false, SelectType::CERTI_LEVEL, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, modOperatorTestbyName) {
    Operator* pOperator = setupData();

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO);
    EmployeeInformation* pModEmployeeInfo = new EmployeeInformation(17112609, "Gildong", "Hong", CareerLevel::CL4, 5645, 6122, 1986, 12, 03, CertiLevel::PRO);

    ProcessResult result = pOperator->modEmployee(true, SelectType::CAREER_LEVEL, *pEmployeeInfo, SelectType::FULL_NAME, *pModEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 2);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    result = pOperator->schEmployee(false, SelectType::FULL_NAME, *pModEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 2);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    pEmployeeInfo->name_.first = "SRERLALH";
    pEmployeeInfo->name_.last = "HMEF";

    result = pOperator->schEmployee(false, SelectType::FULL_NAME, *pEmployeeInfo);
    EXPECT_EQ(result.numOfRecord, 0);
    for (auto it : result.printRecord)
    {
        cout << it << endl;
    }

    delete pEmployeeInfo;
}

TEST_F(OperatorTest, makeRecordTestbyName) {
    Operator* pOperator = setupData();
    vector<EmployeeInformation> list;

    EmployeeInformation* pEmployeeInfo = new EmployeeInformation(15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, 1977, 12, 11, CertiLevel::ADV);

    list.push_back(*pEmployeeInfo);

    pEmployeeInfo->employeeNumber_ = 19129568;
    pEmployeeInfo->name_.first = "SRERLALH";
    pEmployeeInfo->name_.last = "HMEF";
    pEmployeeInfo->careerLevel_ = CareerLevel::CL2;
    pEmployeeInfo->phoneNumber_.mid = 3091;
    pEmployeeInfo->phoneNumber_.last = 9521;
    pEmployeeInfo->birthday_ = { 1964, 9, 10 };
    pEmployeeInfo->certiLevel_ = CertiLevel::PRO;

    list.push_back(*pEmployeeInfo);

    vector<string> result = pOperator->getRecordMaker()->makeRecord(true, Command::DEL, list);

    for (auto str : result)
    {
        std::cout << str << endl;
    }

    delete pEmployeeInfo;
}
