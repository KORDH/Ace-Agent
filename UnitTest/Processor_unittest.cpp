#include "pch.h"
#include "Processor_unittest.h"
#include "MockAddCommandProcessor.h"
#include "TestUtil.h"
#include "../AceAgent/Processor.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST_F(FixtureAddCommandProcessor, SuccessToAdd) {
	FEATURE("ADDCommandProcessor은 data Manager에 employee를 등록할 수 있다.");
	SCENARIO("data Manager에 employee를 등록한다.");

	GIVEN("1명의 employee 정보가 있다.");
	EmployeeInfomation employeeInfomation(14037560,"GILDONG","HONG",CareerLevel::CL2,2345,3948,1960,12,31,CertiLevel::PRO);
	AddCommandProcessor addCommandProcessor(mockProcessor_);

	WHEN("employee를 add 했을 때");
	THEN("모든 정보를 1번만 로딩해야 하고,");
	EXPECT_CALL(mockProcessor_, addEmployee(_)).Times(1);
	
	addCommandProcessor.runCommand(employeeInfomation);

	AND("종료되어야 한다.");
}
