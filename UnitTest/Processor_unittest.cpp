#include "pch.h"
#include "Processor_unittest.h"
#include "MockAddCommandProcessor.h"
#include "TestUtil.h"
#include "../AceAgent/Processor.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST_F(FixtureAddCommandProcessor, SuccessToAdd) {
	FEATURE("ADDCommandProcessor�� data Manager�� employee�� ����� �� �ִ�.");
	SCENARIO("data Manager�� employee�� ����Ѵ�.");

	GIVEN("1���� employee ������ �ִ�.");
	EmployeeInfomation employeeInfomation(14037560,"GILDONG","HONG",CareerLevel::CL2,2345,3948,1960,12,31,CertiLevel::PRO);
	AddCommandProcessor addCommandProcessor(mockProcessor_);

	WHEN("employee�� add ���� ��");
	THEN("��� ������ 1���� �ε��ؾ� �ϰ�,");
	EXPECT_CALL(mockProcessor_, addEmployee(_)).Times(1);
	
	addCommandProcessor.runCommand(employeeInfomation);

	AND("����Ǿ�� �Ѵ�.");
}
