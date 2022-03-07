#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInformation& employeeInfomation) = 0;
	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInformation) = 0;
	virtual ProcessResult* searchEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation) = 0;
	virtual ProcessResult* modifyEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation, const SelectType modifyType, EmployeeInformation* modiyInformation) = 0;
};