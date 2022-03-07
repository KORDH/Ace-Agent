#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "SelectType.h"
#include "EmployeeInformation.h"
#include "datamanager.h"

using namespace std;

class SearchManager {
public:
	vector<EmployeeInformation> SearchEmployeeData(DataManager* pDataManager, SelectType searchType, EmployeeInformation employeeInformation);
	vector<EmployeeInformation> SearchEmployeeInformation(map<unsigned int, EmployeeInformation>& DataMap, SelectType searchType, EmployeeInformation employeeInformation);

private:
	bool isSameData(SelectType searchType, EmployeeInformation EmployeeDataInDB, EmployeeInformation EmployeeDataForSearch) {
		switch (searchType) {
		case SelectType::EMPLOYEE_NUMBER:
			return EmployeeDataInDB.employeeNumber_ == EmployeeDataForSearch.employeeNumber_;

		case SelectType::FULL_NAME:
			return (EmployeeDataInDB.name_.first == EmployeeDataForSearch.name_.first && EmployeeDataInDB.name_.last == EmployeeDataForSearch.name_.last);

		case SelectType::FIRST_NAME:
			return EmployeeDataInDB.name_.first == EmployeeDataForSearch.name_.first;

		case SelectType::LAST_NAME:
			return EmployeeDataInDB.name_.last == EmployeeDataForSearch.name_.last;

		case SelectType::FULL_BIRTHDAY:
			return (EmployeeDataInDB.birthday_.year_ == EmployeeDataForSearch.birthday_.year_
				&& EmployeeDataInDB.birthday_.month_ == EmployeeDataForSearch.birthday_.month_
				&& EmployeeDataInDB.birthday_.day_ == EmployeeDataForSearch.birthday_.day_);

		case SelectType::YEAR_OF_BIRTHDAY:
			return EmployeeDataInDB.birthday_.year_ == EmployeeDataForSearch.birthday_.year_;

		case SelectType::MONTH_OF_BIRTHDAY:
			return EmployeeDataInDB.birthday_.month_ == EmployeeDataForSearch.birthday_.month_;

		case SelectType::DAY_OF_BIRTHDAY:
			return EmployeeDataInDB.birthday_.day_ == EmployeeDataForSearch.birthday_.day_;

		case SelectType::FULL_PHONE_NUMBER:
			return (EmployeeDataInDB.phoneNumber_.last == EmployeeDataForSearch.phoneNumber_.last
				&& EmployeeDataInDB.phoneNumber_.mid == EmployeeDataForSearch.phoneNumber_.mid);

		case SelectType::MID_PHONE_NUMBER:
			return (EmployeeDataInDB.phoneNumber_.mid == EmployeeDataForSearch.phoneNumber_.mid);

		case SelectType::LAST_PHONE_NUMBER:
			return (EmployeeDataInDB.phoneNumber_.last == EmployeeDataForSearch.phoneNumber_.last);

		case SelectType::CAREER_LEVEL:
			return (EmployeeDataInDB.careerLevel_ == EmployeeDataForSearch.careerLevel_);

		case SelectType::CERTI_LEVEL:
			return (EmployeeDataInDB.certiLevel_ == EmployeeDataForSearch.certiLevel_);

		default:
			return 0;
		}
	}
};