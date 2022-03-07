#include "SearchManager.h"

vector<EmployeeInformation> SearchManager::SearchEmployeeData(DataManager* pDataManager, SelectType searchType, EmployeeInformation employeeInformation) {
	vector <EmployeeInformation> result;
	map<unsigned int, EmployeeInformation> DataMap;

	result.clear();

	DataMap = pDataManager->getEmployeeMap();

	switch (searchType) {
	case SelectType::EMPLOYEE_NUMBER:
		return SearchEmployeeNumber(DataMap, employeeInformation);
	case SelectType::FULL_NAME:
		return SearchEmployeeName(DataMap, employeeInformation);
	case SelectType::FIRST_NAME:
		return SearchEmployeeFirstName(DataMap, employeeInformation);
	case SelectType::LAST_NAME:
		return SearchEmployeeLastName(DataMap, employeeInformation);
	case SelectType::FULL_BIRTHDAY:
		return SearchEmployeeBirthday(DataMap, employeeInformation);
	case SelectType::YEAR_OF_BIRTHDAY:
		return SearchEmployeeYearOfBirthday(DataMap, employeeInformation);
	case SelectType::MONTH_OF_BIRTHDAY:
		return SearchEmployeeMonthOfBirthday(DataMap, employeeInformation);
	case SelectType::DAY_OF_BIRTHDAY:
		return SearchEmployeeDayOfBirthday(DataMap, employeeInformation);
	case SelectType::FULL_PHONE_NUMBER:
		return SearchEmployeePhoneNumber(DataMap, employeeInformation);
	case SelectType::MID_PHONE_NUMBER:
		return SearchEmployeeMidPhoneNumber(DataMap, employeeInformation);
	case SelectType::LAST_PHONE_NUMBER:
		return SearchEmployeeLastPhoneNumber(DataMap, employeeInformation);
	case SelectType::CAREER_LEVEL:
		return SearchEmployeeCareerLevel(DataMap, employeeInformation);
	case SelectType::CERTI_LEVEL:
		return SearchEmployeeCertiLevel(DataMap, employeeInformation);
	default:
		cout << "해당 Type으로 검색이 불가능합니다. 다시 입력해주세요." << endl;
		break;
	}

	return result;
}




