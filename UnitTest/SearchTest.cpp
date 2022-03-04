#include "pch.h"
#include "../AceAgent/SearchManager.cpp"
#include "TestUtil.h"

void addDataForTest(EmployeeInformation employeeInfo) {
	employeeNumberMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.employeeNumber, employeeInfo));
	yearOfBirthdayMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.yearOfBirthday, employeeInfo));
	monthOfBirthdayMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.monthOfBirthday, employeeInfo));
	dayOfBirthdayMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.dayOfBirthday, employeeInfo));
	careerLevelMap.insert(pair<unsigned int, EmployeeInformation>(employeeInfo.careerLevel, employeeInfo));
	
	certiLevelMap.insert(pair<string, EmployeeInformation>(employeeInfo.certiLevel, employeeInfo));
	fullNameMap.insert(pair<string, EmployeeInformation>(employeeInfo.fullName, employeeInfo));
	firstNameMap.insert(pair<string, EmployeeInformation>(employeeInfo.firstName, employeeInfo));
	lastNameMap.insert(pair<string, EmployeeInformation>(employeeInfo.lastName, employeeInfo));
	phoneNumberMap.insert(pair<string, EmployeeInformation>(employeeInfo.phoneNumber, employeeInfo));
	midPhoneNumberMap.insert(pair<string, EmployeeInformation>(employeeInfo.midPhoneNumber, employeeInfo));
	lastPhoneNumberMap.insert(pair<string, EmployeeInformation>(employeeInfo.lastPhoneNumber, employeeInfo));
	birthdayMap.insert(pair<string, EmployeeInformation>(employeeInfo.birthday, employeeInfo));
}

TEST(SearchTest, SearchTestForName) {
	SearchManager searchManager;
	vector<EmployeeInformation> result;
	int cmpresultdata[4] = { 69201111, 70211111, 18028552, 20201111 };
	int cnt = 0;

	FEATURE("Name Search Test는 동일한 name을 가진 employee를 찾을 수 있다.");
	SCENARIO("Database에 저장된 동일한 Full name을 가진 employee들을 반환한다.");

	GIVEN("검색할 Data type과 검색할 name이 주어진다.");

	addDataForTest({ 18028552, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 11122222, 1992,12, 26, 2, "PRO", "Minjeong Kim", "Minjeong", "Kim", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 20221333, 1992,12, 26, 2, "PRO", "DongHo Kim", "Dongho", "Kim", "01072725858", "7272", "5858", "19921226" });
	addDataForTest({ 20201111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 69201111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 70211111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });


	WHEN("검색을 구했을 때");

	result = searchManager.SearchEmployeeData(DataType::FULL_NAME, "Donghyuk Jang");

	AND("동일한 Full name을 가진 vector가 나와야한다.");

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

	cnt = 0;

	AND("동일한 First name을 가진 vector가 나와야한다.");

	result = searchManager.SearchEmployeeData(DataType::FIRST_NAME, "Donghyuk");

	for (const auto& i : result) 
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

	
	AND("동일한 Last name을 가진 vector가 나와야한다.");

	cnt = 0;

	result = searchManager.SearchEmployeeData(DataType::LAST_NAME, "Jang");

	for (const auto& i : result) 
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

}

