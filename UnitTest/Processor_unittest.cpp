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
	EmployeeInfomation employeeInfomation(14037560, "GILDONG", "HONG", CareerLevel::CL2, 2345, 3948, 1960, 12, 31, CertiLevel::PRO);
	AddCommandProcessor addCommandProcessor(mockProcessor_);

	WHEN("employee를 add 했을 때");
	THEN("모든 정보를 1번만 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, addEmployee(_)).Times(1);

	addCommandProcessor.runCommand(employeeInfomation);

	AND("종료되어야 한다.");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByEmployeeNumberWithoutDetailPrint) {
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
	EmployeeInfomation employeeInfomation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("1명이 삭제되어야 한다");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
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
	EmployeeInfomation employeeInfomation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("2명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
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
	EmployeeInfomation employeeInfomation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
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
	EmployeeInfomation employeeInfomation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("4명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115044");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("9명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 9);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "88114052");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "1122329");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "5101762");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "8108827");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("2명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("5명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("5명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("7명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("7명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "3113260");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
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
	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("12명이 삭제되어야 한다");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "10127115");
}