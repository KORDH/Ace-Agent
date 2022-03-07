#pragma once

#include "EmployeeInformation.h"
#include "ProcessResult.h"
#include "SelectType.h"
#include "IDataManager.h"

#define interface struct

class CommandProcessor {
public:
	virtual void runCommand(EmployeeInformation& employeeInformation) = 0;
};

class AddCommandProcessor : public CommandProcessor {
public:
	AddCommandProcessor(IDataManager& processor);
	~AddCommandProcessor();

	virtual void runCommand(EmployeeInformation& employeeInformation) override {
		processor_.addEmployee(employeeInformation);
	}
protected:
	IDataManager& processor_;
private:

};

class DeleteCommandProcessor : public CommandProcessor {
public:
	DeleteCommandProcessor(IDataManager& processor);
	~DeleteCommandProcessor();

	virtual void runCommand(EmployeeInformation& employeeInformation) override {
		setProcessResult(processor_.deleteEmployee(isDetailPrint_, deleteType_, employeeInformation));
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

	virtual void runCommand(EmployeeInformation& employeeInformation) override {
		setProcessResult(processor_.searchEmployee(isDetailPrint_, searchType_, employeeInformation));
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


class ModifyCommandProcessor : public CommandProcessor {
public:
	ModifyCommandProcessor(IDataManager& processor);
	~ModifyCommandProcessor();

	virtual void runCommand(EmployeeInformation& employeeInformation) override {
		setProcessResult(processor_.modifyEmployee(isDetailPrint_, searchType_, employeeInformation, modifyType_, modifyInformation_));
	}

	void setModifyInformation(bool isDetailPrint, SelectType searchType, SelectType modifyType, EmployeeInformation* modifyInformation);
	ProcessResult* getProcessResult();
	void setProcessResult(ProcessResult* processResult);

protected:
	IDataManager& processor_;

private:
	bool isDetailPrint_ = false;
	SelectType searchType_ = SelectType::NONE;
	SelectType modifyType_ = SelectType::NONE;
	EmployeeInformation* modifyInformation_;
	ProcessResult* processResult_ = nullptr;
};