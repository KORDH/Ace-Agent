#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInfomation& employeeInfomation) = 0;
	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInfomation& deleteInfomation) = 0;
	virtual ProcessResult* searchEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInfomation& searchInfomation) = 0;
	virtual ProcessResult* modifyEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInfomation& searchInfomation, const SelectType modifyType, EmployeeInfomation* modiyInfomation) = 0;
};