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
	vector<EmployeeInformation> SearchEmployeeData(DataManager *pDataManager ,SelectType searchType, EmployeeInformation employeeInformation);

	vector<EmployeeInformation> SearchEmployeeNumber(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.employeeNumber_ == employeeInformation.employeeNumber_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeName(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.name_.first == employeeInformation.name_.first && iter->second.name_.last == employeeInformation.name_.last) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeFirstName(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.name_.first == employeeInformation.name_.first) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeLastName(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.name_.last == employeeInformation.name_.last) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeBirthday(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.birthday_.year_ == employeeInformation.birthday_.year_
				&& iter->second.birthday_.month_ == employeeInformation.birthday_.month_
				&& iter->second.birthday_.day_ == employeeInformation.birthday_.day_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeYearOfBirthday(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.birthday_.year_ == employeeInformation.birthday_.year_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeMonthOfBirthday(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.birthday_.month_ == employeeInformation.birthday_.month_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeDayOfBirthday(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.birthday_.day_ == employeeInformation.birthday_.day_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeePhoneNumber(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.phoneNumber_.last == employeeInformation.phoneNumber_.last
				&& iter->second.phoneNumber_.mid == employeeInformation.phoneNumber_.mid) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeMidPhoneNumber(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.phoneNumber_.mid == employeeInformation.phoneNumber_.mid) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeLastPhoneNumber(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.phoneNumber_.last == employeeInformation.phoneNumber_.last) {
				result.push_back(iter->second);
			}
		}
		return result;
	}


	vector<EmployeeInformation> SearchEmployeeCareerLevel(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.careerLevel_ == employeeInformation.careerLevel_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}

	vector<EmployeeInformation> SearchEmployeeCertiLevel(map<unsigned int, EmployeeInformation>& DataMap, EmployeeInformation employeeInformation) {
		vector <EmployeeInformation> result;

		for (auto iter = DataMap.begin(); iter != DataMap.end(); iter++)
		{
			if (iter->second.certiLevel_ == employeeInformation.certiLevel_) {
				result.push_back(iter->second);
			}
		}
		return result;
	}
};