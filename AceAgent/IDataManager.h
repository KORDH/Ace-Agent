#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInfomation& employeeInfomation) = 0;
	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInfomation& deleteInfomation) = 0;
};