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

	FEATURE("SearchTestForEmployeeNumber는 동일한 EmployeeNumber을 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 EmployeeNumber을 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 EmployeeNumber이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::EMPLOYEE_NUMBER, searchEmployeeInfo);

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

	FEATURE("SearchTestForFullName는 동일한 FullName을 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 FullName을 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 FullName이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::FULL_NAME, searchEmployeeInfo);

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

	FEATURE("SearchTestForFirstName는 동일한 FirstName을 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 FirstName을 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 FirstName이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);


	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::FIRST_NAME, searchEmployeeInfo);

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

	FEATURE("SearchTestForLastName는 동일한 LastName을 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 LastName을 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 LastName이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::LAST_NAME, searchEmployeeInfo);

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

	FEATURE("SearchTestForBirthday은 동일한 Birthday를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 Birthday를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 Birthday이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::FULL_BIRTHDAY, searchEmployeeInfo);

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

	FEATURE("SearchTestForYearOfBirthday은 동일한 YearOfBirthday를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 YearOfBirthday를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 YearOfBirthday이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::YEAR_OF_BIRTHDAY, searchEmployeeInfo);

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

	FEATURE("SearchTestForMonthOfBirthday은 동일한 MonthOfBirthday를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 MonthOfBirthday를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 MonthOfBirthday이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::MONTH_OF_BIRTHDAY, searchEmployeeInfo);

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

	FEATURE("SearchTestForDayOfBirthday은 동일한 DayOfBirthday를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 DayOfBirthday를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 DayOfBirthday이 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::DAY_OF_BIRTHDAY, searchEmployeeInfo);

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

	FEATURE("SearchTestForPhoneNumber은 동일한 PhoneNumber를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 PhoneNumber를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 PhoneNumber가 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::FULL_PHONE_NUMBER, searchEmployeeInfo);

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

	FEATURE("SearchTestForMidPhoneNumber은 동일한 MidPhoneNumber를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 MidPhoneNumber를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 MidPhoneNumber가 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::MID_PHONE_NUMBER, searchEmployeeInfo);

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

	FEATURE("SearchTestForLastPhoneNumber은 동일한 LastPhoneNumber를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 LastPhoneNumber를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 LastPhoneNumber가 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::LAST_PHONE_NUMBER, searchEmployeeInfo);

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

	FEATURE("SearchTestForCareerLevel은 동일한 CareerLevel를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 CareerLevel를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 CareerLevel가 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::CAREER_LEVEL, searchEmployeeInfo);

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

	FEATURE("SearchTestForCareerLevel은 동일한 CertiLevel를 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 CertiLevel를 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 CertiLevel가 주어진다.");

	clearDataForTest();

	addDataForTest(employee1);
	addDataForTest(employee2);
	addDataForTest(employee3);
	addDataForTest(employee4);
	addDataForTest(employee5);

	WHEN("검색을 했을 때");

	result = searchManager.SearchEmployeeInformation(TestDataMap, SelectType::CERTI_LEVEL, searchEmployeeInfo);

	EXPECT_EQ(1, result.size());

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber_, ResultData[cnt++]);
}