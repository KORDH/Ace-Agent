#include "pch.h"
#include "Processor_unittest.h"
#include "MockDataManager.h"
#include "TestUtil.h"
#include "../AceAgent/Processor.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST_F(FixtureCommandProcessor, SuccessToAdd) {
	FEATURE("AddCommandProcessor은 data Manager에 employee를 등록할 수 있다.");
	SCENARIO("data Manager에 employee를 등록한다.");

	GIVEN("1명의 employee 정보가 있다.");
	EmployeeInformation employeeInformation(14037560, "GILDONG", "HONG", CareerLevel::CL2, 2345, 3948, 1960, 12, 31, CertiLevel::PRO);
	AddCommandProcessor addCommandProcessor(mockProcessor_);

	WHEN("employee를 add 했을 때");
	THEN("모든 정보를 1번만 로딩해야 하고,");

	addCommandProcessor.runCommand(employeeInformation);

	AND("종료되어야 한다.");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByEmployeeNumber) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::EMPLOYEE_NUMBER);
	EmployeeInformation employeeInformation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("1명이 삭제되어야 한다");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - 1);
	EXPECT_EQ(mockProcessor_.getProcessResult().numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByFullName) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("detailPrint 옵션이 disable되고 employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_NAME);
	EmployeeInformation employeeInformation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("2명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
}


TEST_F(FixtureCommandProcessor, SuccessToDeleteByFristName) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FIRST_NAME);
	EmployeeInformation employeeInformation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByLastName) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::LAST_NAME);
	EmployeeInformation employeeInformation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("4명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByCareerLevel) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::CAREER_LEVEL);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("9명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 9);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "88114052");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "1122329");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "5101762");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "8108827");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByFullPhoneNumber) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("2명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByMidPhoneNumber) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::MID_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByLastPhoneNumber) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::LAST_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByFullBirthday) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("5명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByYearOfBirthday) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::YEAR_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("5명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByMonthOfBirthday) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::MONTH_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("7명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByDayOfBirthday) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::DAY_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("7명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "3113260");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByCertiLevel) {
	FEATURE("DeleteCommandProcessor은 data Manager에 employee를 삭제할 수 있다.");
	SCENARIO("data Manager에 employee를 삭제한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 delete 했을 때");
	THEN("delete는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::CERTI_LEVEL);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInformation);

	AND("12명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "10127115");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByEmployeeNumber) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Search 했을 때");
	THEN("search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::EMPLOYEE_NUMBER);
	EmployeeInformation employeeInformation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("1명이 검색되어야 한다");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(mockProcessor_.getProcessResult().numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullName) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("detailPrint 옵션이 disable되고 employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_NAME);
	EmployeeInformation employeeInformation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("2명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFristName) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FIRST_NAME);
	EmployeeInformation employeeInformation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("3명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByLastName) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::LAST_NAME);
	EmployeeInformation employeeInformation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("4명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByCareerLevel) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::CAREER_LEVEL);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("9명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 9);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "88114052");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "1122329");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "5101762");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "8108827");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullPhoneNumber) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("2명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByMidPhoneNumber) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::MID_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("3명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByLastPhoneNumber) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::LAST_PHONE_NUMBER);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("3명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullBirthday) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("5명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByYearOfBirthday) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::YEAR_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("5명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByMonthOfBirthday) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::MONTH_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("7명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByDayOfBirthday) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::DAY_OF_BIRTHDAY);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("7명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "3113260");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByCertiLevel) {
	FEATURE("SearchCommandProcessor은 data Manager에 employee를 검색할 수 있다.");
	SCENARIO("data Manager에 employee를 검색한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Search 했을 때");
	THEN("Search는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::CERTI_LEVEL);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInformation);

	AND("12명이 검색되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "10127115");
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByEmployeeNumber) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Modify 했을 때");
	THEN("modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation employeeInformation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::EMPLOYEE_NUMBER, SelectType::CERTI_LEVEL, &modifyInformation);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("1명이 수정되어야 한다");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(mockProcessor_.getProcessResult().numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(2117175).getCertiLevel(), CertiLevel::PRO);

}

TEST_F(FixtureCommandProcessor, SuccessToModifyByFullName) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("detailPrint 옵션이 disable되고 employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_NAME, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("2명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByFristName) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::FIRST_NAME, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("3명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByLastName) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::LAST_NAME, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("4명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115044");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115043).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115044).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByCareerLevel) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::CAREER_LEVEL, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("9명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 9);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "88114052");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "1122329");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "5101762");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "8108827");


	EXPECT_EQ(mockProcessor_.getEmployeeInformation(88114052).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(1122329).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(2117175).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(5101762).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(8108827).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByFullPhoneNumber) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_PHONE_NUMBER, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("2명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByMidPhoneNumber) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::MID_PHONE_NUMBER, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("3명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115043");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115043).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByLastPhoneNumber) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::LAST_PHONE_NUMBER, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("3명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByFullBirthday) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_BIRTHDAY, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("5명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115043).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115044).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByYearOfBirthday) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::YEAR_OF_BIRTHDAY, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("5명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115044");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115043).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115044).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByMonthOfBirthday) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::MONTH_OF_BIRTHDAY, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("7명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(2117175).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(17111236).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByDayOfBirthday) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::DAY_OF_BIRTHDAY, SelectType::CERTI_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("7명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "3113260");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "18115042");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(3113260).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(17111236).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115040).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115041).getCertiLevel(), CertiLevel::PRO);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(18115042).getCertiLevel(), CertiLevel::PRO);
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByCertiLevel) {
	FEATURE("ModifyCommandProcessor은 data Manager에 employee를 수정할 수 있다.");
	SCENARIO("data Manager에 employee를 수정한다.");

	GIVEN("set up에 등록된 employee 정보가 있다.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup 등록 employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee를 Modify 했을 때");
	THEN("Modify는 1번 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation modifyInformation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	modifyCommandProcessor.setModifyInformation(false, SelectType::CERTI_LEVEL, SelectType::CAREER_LEVEL, &modifyInformation);
	EmployeeInformation employeeInformation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInformation);

	AND("12명이 수정되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult().numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult().printRecord[4], "10127115");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(85125741).getCareerLevel(), CareerLevel::CL4);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(2117175).getCareerLevel(), CareerLevel::CL4);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(8108827).getCareerLevel(), CareerLevel::CL4);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(8117441).getCareerLevel(), CareerLevel::CL4);
	EXPECT_EQ(mockProcessor_.getEmployeeInformation(10127115).getCareerLevel(), CareerLevel::CL4);
}