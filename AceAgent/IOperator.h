#pragma once

class IOperator {
public:
	virtual ~IOperator() {};
	virtual void addEmployee(EmployeeInformation employeeInfomation) = 0;
	virtual ProcessResult deleteEmployee(bool isDetailPrint, SelectType deleteType, EmployeeInformation deleteInformation) = 0;
	virtual ProcessResult searchEmployee(bool isDetailPrint, SelectType searchType, EmployeeInformation searchInformation) = 0;
	virtual ProcessResult modifyEmployee(bool isDetailPrint, SelectType searchType, EmployeeInformation searchInformation, SelectType modifyType, EmployeeInformation modiyInformation) = 0;
};