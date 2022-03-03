#pragma once

#include "pch.h"
#include <stdexcept>
#include "../AceAgent/Processor.h"

using namespace std;

class MockAddCommandProcessor : public ICommandProcessor {
public:
	MOCK_METHOD(void, addEmployee, (const EmployeeInfomation& employeeInfomation), (override, const));
};