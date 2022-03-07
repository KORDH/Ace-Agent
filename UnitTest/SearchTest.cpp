#include "pch.h"
#include "SearchTest.h"
#include "TestUtil.h"


void addDataForTest(EmployeeInformation employeeInfo) {
	TestDataMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.employeeNumber_, employeeInfo));
}

void clearDataForTest() {
	TestDataMap.clear();
}

TEST(SearchTest, SearchTestForEmployeeNumber) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee3{ 1020201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee4{ 69201111, "Myeongsoo", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForEmployeeNumber�� ������ EmployeeNumber�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ EmployeeNumber�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� EmployeeNumber�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeNumber(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(1, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForFullName) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 80212121, 1017201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee4{ 69201111, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 80212121, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForFullName�� ������ FullName�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ FullName�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� FullName�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeName(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(4, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForFirstName) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 1017201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee4{ 69201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForFirstName�� ������ FirstName�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ FirstName�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� FirstName�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);


	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeFirstName(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForLastName) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForLastName�� ������ LastName�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ LastName�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� LastName�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeLastName(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForBirthday) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 1017201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,11,26, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForBirthday�� ������ Birthday�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ Birthday�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� Birthday�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeBirthday(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForYearOfBirthday) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 70211111, 1017201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForYearOfBirthday�� ������ YearOfBirthday�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ YearOfBirthday�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� YearOfBirthday�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeYearOfBirthday(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(3, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForMonthOfBirthday) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 78201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForMonthOfBirthday�� ������ MonthOfBirthday�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ MonthOfBirthday�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� MonthOfBirthday�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeMonthOfBirthday(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForDayOfBirthday) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 78201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 5487, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL2, 5487, 7949 , 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL2, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForDayOfBirthday�� ������ DayOfBirthday�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ DayOfBirthday�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� DayOfBirthday�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeDayOfBirthday(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(3, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForPhoneNumber) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 70211111, };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 1212, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL1, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 3333, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL3, 5487, 4444, 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL4, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForPhoneNumber�� ������ PhoneNumber�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ PhoneNumber�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� PhoneNumber�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeePhoneNumber(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForMidPhoneNumber) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 70211111, 78201111 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 1212, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL1, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 3333, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL3, 5487, 4444, 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL4, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForMidPhoneNumber�� ������ MidPhoneNumber�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ MidPhoneNumber�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� MidPhoneNumber�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeMidPhoneNumber(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(3, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForLastPhoneNumber) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, 70211111, 1017201111, 1018028552 };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 1212, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL1, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 3333, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL3, 5487, 4444, 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL4, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForLastPhoneNumber�� ������ LastPhoneNumber�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ LastPhoneNumber�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� LastPhoneNumber�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeLastPhoneNumber(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(4, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForCareerLevel) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 1017201111, 1018028552, };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 1212, 7949 , 1992,12,26, CertiLevel::PRO };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL1, 5487, 7949 , 1992,5,12, CertiLevel::PRO };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 3333, 7949 , 1992,1,11, CertiLevel::PRO };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL3, 5487, 4444, 1962,12,26, CertiLevel::PRO };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL4, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForCareerLevel�� ������ CareerLevel�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ CareerLevel�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� CareerLevel�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeCareerLevel(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(2, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}

TEST(SearchTest, SearchTestForCertiLevel) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int ResultData[4] = { 69201111, };
	int cnt = 0;
	EmployeeInformation employee1{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 1212, 7949 , 1992,12,26, CertiLevel::EX };
	EmployeeInformation employee2{ 70211111, "Minjeong", "Kim", CareerLevel::CL1, 5487, 7949 , 1992,5,12, CertiLevel::ADV };
	EmployeeInformation employee3{ 1017201111, "Donghyuk", "Kim", CareerLevel::CL2, 3333, 7949 , 1992,1,11, CertiLevel::EX };
	EmployeeInformation employee4{ 78201111, "Donghee", "Lee", CareerLevel::CL3, 5487, 4444, 1962,12,26, CertiLevel::EX };
	EmployeeInformation employee5{ 69201111, "Donghee", "Jang", CareerLevel::CL4, 5487, 7949 , 2000,1,26, CertiLevel::PRO };

	EmployeeInformation searchEmployeeInfo{ 1018028552, "Donghyuk", "Jang", CareerLevel::CL2, 5487, 7949 , 1992,12,26, CertiLevel::PRO };

	FEATURE("SearchTestForCareerLevel�� ������ CertiLevel�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ CertiLevel�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� CertiLevel�� �־�����.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("�˻��� ���� ��");

	result = searchManager.SearchEmployeeCertiLevel(TestDataMap, searchEmployeeInfo);

	EXPECT_EQ(1, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}