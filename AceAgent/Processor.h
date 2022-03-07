#pragma once

#include "EmployeeInfomation.h"
#include "ProcessResult.h"
#include "SelectType.h"
#include "IDataManager.h"

#define interface struct

class CommandProcessor {
public:
	virtual void runCommand(EmployeeInfomation& employeeInfomation) = 0;
};

class AddCommandProcessor : public CommandProcessor {
public:
	AddCommandProcessor(IDataManager& processor);
	~AddCommandProcessor();

	virtual void runCommand(EmployeeInfomation& employeeInfomation) override {
		processor_.addEmployee(employeeInfomation);
	}
protected:
	IDataManager& processor_;
private:

};

class DeleteCommandProcessor : public CommandProcessor {
public:
	DeleteCommandProcessor(IDataManager& processor);
	~DeleteCommandProcessor();

	virtual void runCommand(EmployeeInfomation& employeeInfomation) override {
		setProcessResult(processor_.deleteEmployee(isDetailPrint_, deleteType_, employeeInfomation));
	}

	void setDeleteInformation(bool isDetailPrint, SelectType deleteType);
	ProcessResult* getProcessResult();
	void setProcessResult(ProcessResult* processResult);

protected:
	IDataManager& processor_;

private:
	bool isDetailPrint_ = false;
	SelectType deleteType_ = SelectType::NONE;
	ProcessResult* processResult_ = nullptr;
};

class SearchCommandProcessor : public CommandProcessor {
public:
	SearchCommandProcessor(IDataManager& processor);
	~SearchCommandProcessor();

	virtual void runCommand(EmployeeInfomation& employeeInfomation) override {
		setProcessResult(processor_.searchEmployee(isDetailPrint_, searchType_, employeeInfomation));
	}

	void setSearchInformation(bool isDetailPrint, SelectType searchType);
	ProcessResult* getProcessResult();
	void setProcessResult(ProcessResult* processResult);

protected:
	IDataManager& processor_;

private:
	bool isDetailPrint_ = false;
	SelectType searchType_ = SelectType::NONE;
	ProcessResult* processResult_ = nullptr;
};