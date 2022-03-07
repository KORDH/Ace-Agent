#include "SearchManager.h"

vector<EmployeeInformation> SearchManager::SearchEmployeeData(DataManager* pDataManager, SelectType searchType, EmployeeInformation employeeInformation) {
	return SearchEmployeeInformation(pDataManager->getEmployeeMap(), searchType, employeeInformation);
}

vector<EmployeeInformation> SearchManager::SearchEmployeeInformation(map<unsigned int, EmployeeInformation>& DataMap, SelectType searchType, EmployeeInformation employeeInformation) {
	vector <EmployeeInformation> result;

	if (searchType == SelectType::NONE) {
		cout << "�ش� Type�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
		return result;
	}

	for (const auto& iter : DataMap)
	{
		if (isSameData(searchType, iter.second, employeeInformation)) {
			result.push_back(iter.second);
		}
	}

	return result;
}



