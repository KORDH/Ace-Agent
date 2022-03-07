#pragma once

class IDataManager {
public:
	virtual ~IDataManager() {};
	virtual void addEmployee(EmployeeInformation employeeInfomation) = 0;
	virtual ProcessResult delEmployee(bool isDetailPrint, SelectType deleteType, EmployeeInformation deleteInformation) = 0;
	virtual ProcessResult schEmployee(bool isDetailPrint, SelectType searchType, EmployeeInformation searchInformation) = 0;
	virtual ProcessResult modEmployee(bool isDetailPrint, SelectType searchType, EmployeeInformation searchInformation, SelectType modifyType, EmployeeInformation modiyInformation) = 0;
};