#pragma once

#include "EmployeeInfomation.h"
#include "ProcessResult.h"
#include "SelectType.h"
#define interface struct

class CommandProcessor {
public:
    virtual void runCommand(const EmployeeInfomation& employeeInfomation) const = 0;
};

class ICommandProcessor {
public:
    virtual ~ICommandProcessor() {};
	virtual void addEmployee(const EmployeeInfomation& employeeInfomation) const = 0;
};

class AddCommandProcessor : public CommandProcessor {
public:
    AddCommandProcessor(ICommandProcessor& processor);
    ~AddCommandProcessor();

    virtual void runCommand(const EmployeeInfomation& employeeInfomation) const override {
        processor_.addEmployee(employeeInfomation);
    }
protected:
	ICommandProcessor& processor_;

private:

};