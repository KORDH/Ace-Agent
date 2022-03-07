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

	FEATURE("Name Search Test�� ������ name�� ���� employee�� ã�� �� �ִ�.");
	SCENARIO("Database�� ����� ������ Full name�� ���� employee���� ��ȯ�Ѵ�.");

	GIVEN("�˻��� Data type�� �˻��� name�� �־�����.");

	addDataForTest({ 18028552, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 11122222, 1992,12, 26, 2, "PRO", "Minjeong Kim", "Minjeong", "Kim", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 20221333, 1992,12, 26, 2, "PRO", "DongHo Kim", "Dongho", "Kim", "01072725858", "7272", "5858", "19921226" });
	addDataForTest({ 20201111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 69201111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });
	addDataForTest({ 70211111, 1992,12, 26, 2, "PRO", "Donghyuk Jang", "Donghyuk", "Jang", "01054877949", "5487", "7949", "19921226" });


	WHEN("�˻��� ������ ��");

	result = searchManager.SearchEmployeeData(DataType::FULL_NAME, "Donghyuk Jang");

	AND("������ Full name�� ���� vector�� ���;��Ѵ�.");

	for (const auto& i : result)
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

	cnt = 0;

	AND("������ First name�� ���� vector�� ���;��Ѵ�.");

	result = searchManager.SearchEmployeeData(DataType::FIRST_NAME, "Donghyuk");

	for (const auto& i : result) 
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

	
	AND("������ Last name�� ���� vector�� ���;��Ѵ�.");

	cnt = 0;

	result = searchManager.SearchEmployeeData(DataType::LAST_NAME, "Jang");

	for (const auto& i : result) 
		EXPECT_EQ(i.employeeNumber, cmpresultdata[cnt++]);

}

