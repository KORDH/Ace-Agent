#include "pch.h"
#include "Processor_unittest.h"
#include "MockDataManager.h"
#include "TestUtil.h"
#include "../AceAgent/Processor.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST_F(FixtureCommandProcessor, SuccessToAdd) {
	FEATURE("AddCommandProcessor�� data Manager�� employee�� ����� �� �ִ�.");
	SCENARIO("data Manager�� employee�� ����Ѵ�.");

	GIVEN("1���� employee ������ �ִ�.");
	EmployeeInformation employeeInfomation(14037560, "GILDONG", "HONG", CareerLevel::CL2, 2345, 3948, 1960, 12, 31, CertiLevel::PRO);
	AddCommandProcessor addCommandProcessor(mockProcessor_);

	WHEN("employee�� add ���� ��");
	THEN("��� ������ 1���� �ε��ؾ� �ϰ�,");

	addCommandProcessor.runCommand(employeeInfomation);

	AND("����Ǿ�� �Ѵ�.");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByEmployeeNumber) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::EMPLOYEE_NUMBER);
	EmployeeInformation employeeInfomation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("1���� �����Ǿ�� �Ѵ�");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByFullName) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("detailPrint �ɼ��� disable�ǰ� employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_NAME);
	EmployeeInformation employeeInfomation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("2���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
}


TEST_F(FixtureCommandProcessor, SuccessToDeleteByFristName) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FIRST_NAME);
	EmployeeInformation employeeInfomation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByLastName) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::LAST_NAME);
	EmployeeInformation employeeInfomation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("4���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByCareerLevel) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::CAREER_LEVEL);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("9���� �����Ǿ�� �Ѵ�");
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
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("2���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByMidPhoneNumber) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::MID_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByLastPhoneNumber) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::LAST_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToDeleteByFullBirthday) {
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::FULL_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("5���� �����Ǿ�� �Ѵ�");
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
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::YEAR_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("5���� �����Ǿ�� �Ѵ�");
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
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::MONTH_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("7���� �����Ǿ�� �Ѵ�");
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
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::DAY_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("7���� �����Ǿ�� �Ѵ�");
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
	FEATURE("DeleteCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� delete ���� ��");
	THEN("delete�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, deleteEmployee(_, _, _)).Times(1);

	DeleteCommandProcessor deleteCommandProcessor(mockProcessor_);
	deleteCommandProcessor.setDeleteInformation(false, SelectType::CERTI_LEVEL);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	deleteCommandProcessor.runCommand(employeeInfomation);

	AND("12���� �����Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager - result);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "10127115");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByEmployeeNumber) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� Search ���� ��");
	THEN("search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::EMPLOYEE_NUMBER);
	EmployeeInformation employeeInfomation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("1���� �˻��Ǿ�� �Ѵ�");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(mockProcessor_.getProcessResult()->numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullName) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("detailPrint �ɼ��� disable�ǰ� employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_NAME);
	EmployeeInformation employeeInfomation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("2���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFristName) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FIRST_NAME);
	EmployeeInformation employeeInfomation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByLastName) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::LAST_NAME);
	EmployeeInformation employeeInfomation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("4���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 4);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByCareerLevel) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::CAREER_LEVEL);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("9���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 9);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "88114052");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "1122329");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "5101762");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "8108827");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullPhoneNumber) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("2���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 2);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByMidPhoneNumber) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::MID_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByLastPhoneNumber) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::LAST_PHONE_NUMBER);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("3���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 3);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByFullBirthday) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::FULL_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("5���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByYearOfBirthday) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::YEAR_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("5���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 5);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByMonthOfBirthday) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::MONTH_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("7���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByDayOfBirthday) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::DAY_OF_BIRTHDAY);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("7���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 7);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "3113260");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
}

TEST_F(FixtureCommandProcessor, SuccessToSearchByCertiLevel) {
	FEATURE("SearchCommandProcessor�� data Manager�� employee�� �˻��� �� �ִ�.");
	SCENARIO("data Manager�� employee�� �˻��Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN(" employee�� Search ���� ��");
	THEN("Search�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, searchEmployee(_, _, _)).Times(1);

	SearchCommandProcessor searchCommandProcessor(mockProcessor_);
	searchCommandProcessor.setSearchInformation(false, SelectType::CERTI_LEVEL);
	EmployeeInformation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
	ProcessResult* pr = new ProcessResult();
	searchCommandProcessor.runCommand(employeeInfomation);

	AND("12���� �˻��Ǿ�� �Ѵ�");
	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(result, 12);

	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "85125741");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "2117175");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "8108827");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "8117441");
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "10127115");
}

TEST_F(FixtureCommandProcessor, SuccessToModifyByEmployeeNumber) {
	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
	SCENARIO("data Manager�� employee�� �����Ѵ�.");

	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;

	WHEN("employee�� Modify ���� ��");
	THEN("modify�� 1�� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);

	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
	EmployeeInformation employeeInfomation(2117175, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
	EmployeeInformation modifyInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::PRO);
	modifyCommandProcessor.setModifyInformation(false, SelectType::EMPLOYEE_NUMBER, SelectType::CERTI_LEVEL,&modifyInfomation);
	ProcessResult* pr = new ProcessResult();
	modifyCommandProcessor.runCommand(employeeInfomation);

	AND("1���� �����Ǿ�� �Ѵ�");
	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
	EXPECT_EQ(mockProcessor_.getProcessResult()->numOfRecord, 1);
	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");

	EXPECT_EQ(mockProcessor_.getEmployeeInformation(2117175).getCertiLevel(), CertiLevel::PRO);

}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByFullName) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN("detailPrint �ɼ��� disable�ǰ� employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_NAME);
//	EmployeeInfomation employeeInfomation(0, "TTETHU", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("2���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 2);
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByFristName) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN("employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::FIRST_NAME);
//	EmployeeInfomation employeeInfomation(0, "TTETHU", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("3���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 3);
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByLastName) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN("employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::LAST_NAME);
//	EmployeeInfomation employeeInfomation(0, "", "HBO", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("4���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 4);
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115044");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByCareerLevel) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::CAREER_LEVEL);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::CL4, 0, 0, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("9���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 9);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "88114052");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "1122329");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "2117175");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "5101762");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "8108827");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByFullPhoneNumber) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_PHONE_NUMBER);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 2050, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("2���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 2);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByMidPhoneNumber) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::MID_PHONE_NUMBER);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 4581, 0, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("3���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 3);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115043");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByLastPhoneNumber) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::LAST_PHONE_NUMBER);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 2050, 0, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("3���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 3);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByFullBirthday) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::FULL_BIRTHDAY);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 7, 18, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("5���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 5);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByYearOfBirthday) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::YEAR_OF_BIRTHDAY);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 2008, 0, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("5���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 5);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115042");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115043");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115044");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByMonthOfBirthday) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::MONTH_OF_BIRTHDAY);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 7, 0, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("7���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 7);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "2117175");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByDayOfBirthday) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::DAY_OF_BIRTHDAY);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 18, CertiLevel::NONE);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("7���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 7);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "3113260");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "17111236");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "18115040");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "18115041");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "18115042");
//}
//
//TEST_F(FixtureCommandProcessor, SuccessToModifyByCertiLevel) {
//	FEATURE("ModifyCommandProcessor�� data Manager�� employee�� ������ �� �ִ�.");
//	SCENARIO("data Manager�� employee�� �����Ѵ�.");
//
//	GIVEN("set up�� ��ϵ� employee ������ �ִ�.");
//	size_t numOfFakeDataManager = mockProcessor_.getNumOfFakeDataManager();
//	std::cout << "setup ��� employee count : " << numOfFakeDataManager << std::endl;
//
//	WHEN(" employee�� Modify ���� ��");
//	THEN("Modify�� 1�� �ε��ؾ� �ϰ�,");
//	EXPECT_CALL(mockProcessor_, modifyEmployee(_, _, _, _, _)).Times(1);
//
//	ModifyCommandProcessor modifyCommandProcessor(mockProcessor_);
//	modifyCommandProcessor.setModifyInformation(false, SelectType::CERTI_LEVEL);
//	EmployeeInfomation employeeInfomation(0, "", "", CareerLevel::NONE, 0, 0, 0, 0, 0, CertiLevel::ADV);
//	ProcessResult* pr = new ProcessResult();
//	modifyCommandProcessor.runCommand(employeeInfomation);
//
//	AND("12���� �����Ǿ�� �Ѵ�");
//	unsigned int result = mockProcessor_.getProcessResult()->numOfRecord;
//	EXPECT_EQ(mockProcessor_.getNumOfFakeDataManager(), numOfFakeDataManager);
//	EXPECT_EQ(result, 12);
//
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[0], "85125741");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[1], "2117175");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[2], "8108827");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[3], "8117441");
//	EXPECT_EQ(mockProcessor_.getProcessResult()->printRecord[4], "10127115");
//}