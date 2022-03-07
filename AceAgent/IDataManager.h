#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInformation& employeeInfomation) = 0;
	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInfomation) = 0;
};