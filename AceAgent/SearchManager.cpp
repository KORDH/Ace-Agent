#include "SearchManager.h"

multimap<unsigned int, EmployeeInformation> SearchManager::getIntegerDataMap(DataType searchType) {
	multimap<unsigned int, EmployeeInformation> result;
	switch (searchType) {
	case DataType::EMPLOYEE_NUMBER:
		result = employeeNumberMap;
		break;
	case DataType::YEAR_OF_BIRTHDAY:
		result = yearOfBirthdayMap;
		break;
	case DataType::MONTH_OF_BIRTHDAY:
		result = monthOfBirthdayMap;
		break;
	case DataType::DAY_OF_BIRTHDAY:
		result = dayOfBirthdayMap;
		break;
	case DataType::CAREER_LEVEL:
		result = careerLevelMap;
		break;
	deault:
		cout << "getDataMap : DataType이 비정상적입니다." << endl;
		break;
	}

	return result;
}

multimap<string, EmployeeInformation> SearchManager::getCharacterDataMap(DataType searchType) {
	multimap<string, EmployeeInformation> result;
	switch (searchType) {
	case DataType::CERTI_LEVEL:
		result = certiLevelMap;
		break;
	case DataType::FULL_NAME:
		result = fullNameMap;
		break;
	case DataType::FIRST_NAME:
		result = firstNameMap;
		break;
	case DataType::LAST_NAME:
		result = lastNameMap;
		break;
	case DataType::PHONE_NUMBER:
		result = phoneNumberMap;
		break;
	case DataType::MID_PHONE_NUMBER:
		result = midPhoneNumberMap;
		break;
	case DataType::LAST_PHONE_NUMBER:
		result = lastPhoneNumberMap;
		break;
	case DataType::BIRTHDAY:
		result = birthdayMap;
		break;
	deault:
		cout << "getDataMap : DataType이 비정상적입니다." << endl;
		break;
	}

	return result;
}

vector<EmployeeInformation> SearchManager::SearchEmployeeData(DataType searchType, unsigned int keyData) {
	vector <EmployeeInformation> result;
	multimap<unsigned int, EmployeeInformation> DataMap = getIntegerDataMap(searchType);

	if (DataMap.count(keyData) == 0) {
		cout << "SearchManager(Character) : 해당 KeyData를 가진 employee가 없습니다." << endl;
		return result;
	}

	for (auto i = DataMap.lower_bound(keyData); i != DataMap.upper_bound(keyData); i++)
	{
		result.push_back(i->second);
		// cout << "result data : " << i->second.employeeNumber << endl;
	}

	sort(result.begin(), result.end(), cmp);

	return result;
}

vector<EmployeeInformation> SearchManager::SearchEmployeeData(DataType searchType, string keyData) {
	vector <EmployeeInformation> result;
	multimap<string, EmployeeInformation> DataMap = getCharacterDataMap(searchType);

	if (DataMap.count(keyData) == 0) {
		cout << "SearchManager(Character) : 해당 KeyData를 가진 employee가 없습니다." << endl;
		return result;
	}

	for (auto i = DataMap.lower_bound(keyData); i != DataMap.upper_bound(keyData); i++)
	{
		result.push_back(i->second);
		// cout << "result data : " << i->second.employeeNumber << endl;
	}

	sort(result.begin(), result.end(), cmp);

	return result;
}


