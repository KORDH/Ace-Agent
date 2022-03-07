#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInformation& employeeInfomation) = 0;
	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInfomation) = 0;
	virtual ProcessResult* searchEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInfomation) = 0;
	virtual ProcessResult* modifyEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInfomation, const SelectType modifyType, EmployeeInformation* modiyInfomation) = 0;
};