#pragma once

#include "pch.h"
#include <stdexcept>
#include "../AceAgent/Processor.h"
#include "../AceAgent/SelectType.h"
#include "../AceAgent/ProcessResult.h"
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

class FakeDataManager : public IDataManager {
public:
	FakeDataManager() {
	}
	virtual void addEmployee(EmployeeInformation& EmployeeInformation)
	{
		unsigned int employeeNumber = EmployeeInformation.getEmployeeNumber();
		string fullName = EmployeeInformation.getFirstName() + " " + EmployeeInformation.getLastName();
		unsigned int fullPhone = (EmployeeInformation.getMidPhoneNumber() * 10000) + EmployeeInformation.getLastPhoneNumber();
		unsigned int fullBrithday = (EmployeeInformation.getBirthday().getYear() * 10000) + (EmployeeInformation.getBirthday().getMonth() * 100) + (EmployeeInformation.getBirthday().getYear() * 1);

		fakeDataManager_.insert(make_pair(employeeNumber, EmployeeInformation));
		fakeDataManagerFullName_[fullName].push_back(employeeNumber);
		fakeDataManagerFristName_[EmployeeInformation.getFirstName()].push_back(employeeNumber);
		fakeDataManagerLastName_[EmployeeInformation.getLastName()].push_back(employeeNumber);
		fakeDataManagerCareerLevel_[EmployeeInformation.getCareerLevel()].push_back(employeeNumber);;
		fakeDataManagerFullPhoneNumber_[fullPhone].push_back(employeeNumber);;
		fakeDataManagerMidPhoneNumber_[EmployeeInformation.getMidPhoneNumber()].push_back(employeeNumber);;
		fakeDataManagerLastPhoneNumber_[EmployeeInformation.getLastPhoneNumber()].push_back(employeeNumber);;
		fakeDataManagerFullBirthDay_[fullBrithday].push_back(employeeNumber);;
		fakeDataManagerYearOfBirthday_[EmployeeInformation.getBirthday().getYear()].push_back(employeeNumber);;
		fakeDataManagerMonthOfBirthday_[EmployeeInformation.getBirthday().getMonth()].push_back(employeeNumber);;
		fakeDataManagerDayOfBirthday_[EmployeeInformation.getBirthday().getDay()].push_back(employeeNumber);;
		fakeDataManagerCertiLevel_[EmployeeInformation.getCertiLevel()].push_back(employeeNumber);;
	}

	virtual ProcessResult* deleteEmployee(const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInformation)
	{
		unsigned int employeeNumber = deleteInformation.getEmployeeNumber();
		string fullName = deleteInformation.getFirstName() + " " + deleteInformation.getLastName();
		unsigned int fullPhone = (deleteInformation.getMidPhoneNumber() * 10000) + deleteInformation.getLastPhoneNumber();
		unsigned int fullBrithday = (deleteInformation.getBirthday().getYear() * 10000) + (deleteInformation.getBirthday().getMonth() * 100) + (deleteInformation.getBirthday().getYear() * 1);

		if (SelectType::EMPLOYEE_NUMBER == deleteType)
			return deleteEmployeeByEmployeeNumber(deleteInformation.getEmployeeNumber());
		else if (SelectType::FULL_NAME == deleteType)
			return deleteEmployeeMap(fakeDataManagerFullName_, fullName);
		else if (SelectType::FIRST_NAME == deleteType)
			return deleteEmployeeMap(fakeDataManagerFristName_, deleteInformation.getFirstName());
		else if (SelectType::LAST_NAME == deleteType)
			return deleteEmployeeMap(fakeDataManagerLastName_, deleteInformation.getLastName());
		else if (SelectType::CAREER_LEVEL == deleteType)
			return deleteEmployeeMap(fakeDataManagerCareerLevel_, deleteInformation.getCareerLevel());
		else if (SelectType::FULL_PHONE_NUMBER == deleteType)
			return deleteEmployeeMap(fakeDataManagerFullPhoneNumber_, fullPhone);
		else if (SelectType::MID_PHONE_NUMBER == deleteType)
			return deleteEmployeeMap(fakeDataManagerMidPhoneNumber_, deleteInformation.getMidPhoneNumber());
		else if (SelectType::LAST_PHONE_NUMBER == deleteType)
			return deleteEmployeeMap(fakeDataManagerLastPhoneNumber_, deleteInformation.getLastPhoneNumber());
		else if (SelectType::FULL_BIRTHDAY == deleteType)
			return deleteEmployeeMap(fakeDataManagerFullBirthDay_, fullBrithday);
		else if (SelectType::YEAR_OF_BIRTHDAY == deleteType)
			return deleteEmployeeMap(fakeDataManagerYearOfBirthday_, deleteInformation.getBirthday().getYear());
		else if (SelectType::MONTH_OF_BIRTHDAY == deleteType)
			return deleteEmployeeMap(fakeDataManagerMonthOfBirthday_, deleteInformation.getBirthday().getMonth());
		else if (SelectType::DAY_OF_BIRTHDAY == deleteType)
			return deleteEmployeeMap(fakeDataManagerDayOfBirthday_, deleteInformation.getBirthday().getDay());
		else if (SelectType::CERTI_LEVEL == deleteType)
			return deleteEmployeeMap(fakeDataManagerCertiLevel_, deleteInformation.getCertiLevel());
	}

	static bool employeeNumberCompare(const unsigned int& a, const unsigned int& b)
	{
		unsigned int EmployeeNumberA = a;
		unsigned int EmployeeNumberB = b;

		if (EmployeeNumberA < 69000000)
			EmployeeNumberA += 100000000;

		if (EmployeeNumberB < 69000000)
			EmployeeNumberB += 100000000;

		if (EmployeeNumberA > EmployeeNumberB)
			return false;
		else
			return true;
	}

	void eraseVectorByEmplyeeNumber(unsigned int emplyeeNumber, vector <unsigned int>* v)
	{
		for (auto iter = (*v).begin(); iter != (*v).end(); iter++)
		{
			if (*iter == emplyeeNumber)
			{
				(*v).erase(iter);
				break;
			}
		}
	}

	void deleteAllMapByEmployeeNumber(unsigned int emplyeeNumber)
	{
		EmployeeInformation info = fakeDataManager_.at(emplyeeNumber);

		string fullName = info.getFirstName() + " " + info.getLastName();
		unsigned int fullPhone = (info.getMidPhoneNumber() * 10000) + info.getLastPhoneNumber();
		unsigned int fullBrithday = (info.getBirthday().getYear() * 10000) + (info.getBirthday().getMonth() * 100) + (info.getBirthday().getYear() * 1);

		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerFullName_[fullName]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerFristName_[info.getFirstName()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerLastName_[info.getLastName()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerCareerLevel_[info.getCareerLevel()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerFullPhoneNumber_[fullPhone]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerMidPhoneNumber_[info.getMidPhoneNumber()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerLastPhoneNumber_[info.getLastPhoneNumber()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerFullBirthDay_[fullBrithday]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerYearOfBirthday_[info.getBirthday().getYear()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerMonthOfBirthday_[info.getBirthday().getMonth()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerDayOfBirthday_[info.getBirthday().getDay()]);
		eraseVectorByEmplyeeNumber(emplyeeNumber, &fakeDataManagerCertiLevel_[info.getCertiLevel()]);
		fakeDataManager_.erase(emplyeeNumber);
	}

	ProcessResult* deleteEmployeeByEmployeeNumber(unsigned int emplyeeNumber)
	{
		processResult_.numOfRecord = fakeDataManager_.count(emplyeeNumber);

		if (processResult_.numOfRecord)
			processResult_.printRecord[0] = to_string(fakeDataManager_.at(emplyeeNumber).getEmployeeNumber());

		deleteAllMapByEmployeeNumber(emplyeeNumber);

		return &processResult_;
	}

	ProcessResult* deleteEmployeeMap(map <string, vector<unsigned int>>& dataManagerMap, string str)
	{
		processResult_.numOfRecord = dataManagerMap[str].size();
		vector<unsigned int> v = dataManagerMap[str];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			fakeDataManager_.erase(*it);
		}

		v.clear();

		return &processResult_;
	}

	ProcessResult* deleteEmployeeMap(map <CareerLevel, vector<unsigned int>>& dataManagerMap, CareerLevel careerLevel)
	{
		processResult_.numOfRecord = dataManagerMap[careerLevel].size();
		vector<unsigned int> v = dataManagerMap[careerLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			fakeDataManager_.erase(*it);
		}

		v.clear();

		return &processResult_;
	}

	ProcessResult* deleteEmployeeMap(map <unsigned int, vector<unsigned int>>& dataManagerMap, unsigned int searchInt)
	{
		processResult_.numOfRecord = dataManagerMap[searchInt].size();
		vector<unsigned int> v = dataManagerMap[searchInt];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			fakeDataManager_.erase(*it);
		}

		v.clear();

		return &processResult_;
	}

	ProcessResult* deleteEmployeeMap(map <CertiLevel, vector<unsigned int>>& dataManagerMap, CertiLevel certiLevel)
	{
		processResult_.numOfRecord = dataManagerMap[certiLevel].size();
		vector<unsigned int> v = dataManagerMap[certiLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			fakeDataManager_.erase(*it);
		}

		v.clear();

		return &processResult_;
	}

	virtual ProcessResult* searchEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation)
	{
		unsigned int employeeNumber = searchInformation.getEmployeeNumber();
		string fullName = searchInformation.getFirstName() + " " + searchInformation.getLastName();
		unsigned int fullPhone = (searchInformation.getMidPhoneNumber() * 10000) + searchInformation.getLastPhoneNumber();
		unsigned int fullBrithday = (searchInformation.getBirthday().getYear() * 10000) + (searchInformation.getBirthday().getMonth() * 100) + (searchInformation.getBirthday().getYear() * 1);

		if (SelectType::EMPLOYEE_NUMBER == searchType)
			return searchEmployeeByEmployeeNumber(searchInformation.getEmployeeNumber());
		else if (SelectType::FULL_NAME == searchType)
			return searchEmployeeMap(fakeDataManagerFullName_, fullName);
		else if (SelectType::FIRST_NAME == searchType)
			return searchEmployeeMap(fakeDataManagerFristName_, searchInformation.getFirstName());
		else if (SelectType::LAST_NAME == searchType)
			return searchEmployeeMap(fakeDataManagerLastName_, searchInformation.getLastName());
		else if (SelectType::CAREER_LEVEL == searchType)
			return searchEmployeeMap(fakeDataManagerCareerLevel_, searchInformation.getCareerLevel());
		else if (SelectType::FULL_PHONE_NUMBER == searchType)
			return searchEmployeeMap(fakeDataManagerFullPhoneNumber_, fullPhone);
		else if (SelectType::MID_PHONE_NUMBER == searchType)
			return searchEmployeeMap(fakeDataManagerMidPhoneNumber_, searchInformation.getMidPhoneNumber());
		else if (SelectType::LAST_PHONE_NUMBER == searchType)
			return searchEmployeeMap(fakeDataManagerLastPhoneNumber_, searchInformation.getLastPhoneNumber());
		else if (SelectType::FULL_BIRTHDAY == searchType)
			return searchEmployeeMap(fakeDataManagerFullBirthDay_, fullBrithday);
		else if (SelectType::YEAR_OF_BIRTHDAY == searchType)
			return searchEmployeeMap(fakeDataManagerYearOfBirthday_, searchInformation.getBirthday().getYear());
		else if (SelectType::MONTH_OF_BIRTHDAY == searchType)
			return searchEmployeeMap(fakeDataManagerMonthOfBirthday_, searchInformation.getBirthday().getMonth());
		else if (SelectType::DAY_OF_BIRTHDAY == searchType)
			return searchEmployeeMap(fakeDataManagerDayOfBirthday_, searchInformation.getBirthday().getDay());
		else if (SelectType::CERTI_LEVEL == searchType)
			return searchEmployeeMap(fakeDataManagerCertiLevel_, searchInformation.getCertiLevel());
	}

	ProcessResult* searchEmployeeByEmployeeNumber(int empplyeeNumber)
	{
		processResult_.numOfRecord = fakeDataManager_.count(empplyeeNumber);

		if (processResult_.numOfRecord)
			processResult_.printRecord[0] = to_string(fakeDataManager_.at(empplyeeNumber).getEmployeeNumber());

		return &processResult_;
	}

	ProcessResult* searchEmployeeMap(map <string, vector<unsigned int>>& dataManagerMap, string str)
	{
		processResult_.numOfRecord = dataManagerMap[str].size();
		vector<unsigned int> v = dataManagerMap[str];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		return &processResult_;
	}

	ProcessResult* searchEmployeeMap(map <CareerLevel, vector<unsigned int>>& dataManagerMap, CareerLevel careerLevel)
	{
		processResult_.numOfRecord = dataManagerMap[careerLevel].size();
		vector<unsigned int> v = dataManagerMap[careerLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		return &processResult_;
	}

	ProcessResult* searchEmployeeMap(map <unsigned int, vector<unsigned int>>& dataManagerMap, unsigned int searchInt)
	{
		processResult_.numOfRecord = dataManagerMap[searchInt].size();
		vector<unsigned int> v = dataManagerMap[searchInt];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		return &processResult_;
	}

	ProcessResult* searchEmployeeMap(map <CertiLevel, vector<unsigned int>>& dataManagerMap, CertiLevel certiLevel)
	{
		processResult_.numOfRecord = dataManagerMap[certiLevel].size();
		vector<unsigned int> v = dataManagerMap[certiLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		return &processResult_;
	}

	virtual ProcessResult* modifyEmployee(const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		unsigned int employeeNumber = searchInformation.getEmployeeNumber();
		string fullName = searchInformation.getFirstName() + " " + searchInformation.getLastName();
		unsigned int fullPhone = (searchInformation.getMidPhoneNumber() * 10000) + searchInformation.getLastPhoneNumber();
		unsigned int fullBrithday = (searchInformation.getBirthday().getYear() * 10000) + (searchInformation.getBirthday().getMonth() * 100) + (searchInformation.getBirthday().getYear() * 1);

		if (SelectType::EMPLOYEE_NUMBER == searchType)
			return modifyEmployeeByEmployeeNumber(searchInformation.getEmployeeNumber(), modifyType, modifyInformation);
		else if (SelectType::FULL_NAME == searchType)
			return modifyEmployeeMap(fakeDataManagerFullName_, fullName, modifyType, modifyInformation);
		else if (SelectType::FIRST_NAME == searchType)
			return modifyEmployeeMap(fakeDataManagerFristName_, searchInformation.getFirstName(), modifyType, modifyInformation);
		else if (SelectType::LAST_NAME == searchType)
			return modifyEmployeeMap(fakeDataManagerLastName_, searchInformation.getLastName(), modifyType, modifyInformation);
		else if (SelectType::CAREER_LEVEL == searchType)
			return modifyEmployeeMap(fakeDataManagerCareerLevel_, searchInformation.getCareerLevel(), modifyType, modifyInformation);
		else if (SelectType::FULL_PHONE_NUMBER == searchType)
			return modifyEmployeeMap(fakeDataManagerFullPhoneNumber_, fullPhone, modifyType, modifyInformation);
		else if (SelectType::MID_PHONE_NUMBER == searchType)
			return modifyEmployeeMap(fakeDataManagerMidPhoneNumber_, searchInformation.getMidPhoneNumber(), modifyType, modifyInformation);
		else if (SelectType::LAST_PHONE_NUMBER == searchType)
			return modifyEmployeeMap(fakeDataManagerLastPhoneNumber_, searchInformation.getLastPhoneNumber(), modifyType, modifyInformation);
		else if (SelectType::FULL_BIRTHDAY == searchType)
			return modifyEmployeeMap(fakeDataManagerFullBirthDay_, fullBrithday, modifyType, modifyInformation);
		else if (SelectType::YEAR_OF_BIRTHDAY == searchType)
			return modifyEmployeeMap(fakeDataManagerYearOfBirthday_, searchInformation.getBirthday().getYear(), modifyType, modifyInformation);
		else if (SelectType::MONTH_OF_BIRTHDAY == searchType)
			return modifyEmployeeMap(fakeDataManagerMonthOfBirthday_, searchInformation.getBirthday().getMonth(), modifyType, modifyInformation);
		else if (SelectType::DAY_OF_BIRTHDAY == searchType)
			return modifyEmployeeMap(fakeDataManagerDayOfBirthday_, searchInformation.getBirthday().getDay(), modifyType, modifyInformation);
		else if (SelectType::CERTI_LEVEL == searchType)
			return modifyEmployeeMap(fakeDataManagerCertiLevel_, searchInformation.getCertiLevel(), modifyType, modifyInformation);
	}

	void modifyEmployeeInformation(const SelectType modifyType, EmployeeInformation* targetInformation, EmployeeInformation* modifyInformation)
	{
		if (SelectType::FIRST_NAME == modifyType)
			targetInformation->setFirstName(modifyInformation->getFirstName());
		else if (SelectType::LAST_NAME == modifyType)
			targetInformation->setLastName(modifyInformation->getLastName());
		else if (SelectType::CAREER_LEVEL == modifyType)
			targetInformation->setCareerLevel(modifyInformation->getCareerLevel());
		else if (SelectType::MID_PHONE_NUMBER == modifyType)
			targetInformation->setMidPhoneNumber(modifyInformation->getMidPhoneNumber());
		else if (SelectType::LAST_PHONE_NUMBER == modifyType)
			targetInformation->setLastPhoneNumber(modifyInformation->getLastPhoneNumber());
		else if (SelectType::YEAR_OF_BIRTHDAY == modifyType)
			targetInformation->setYearOfBirthday(modifyInformation->getBirthday());
		else if (SelectType::MONTH_OF_BIRTHDAY == modifyType)
			targetInformation->setMonthOfBirthday(modifyInformation->getBirthday());
		else if (SelectType::DAY_OF_BIRTHDAY == modifyType)
			targetInformation->setDayOfBirthday(modifyInformation->getBirthday());
		else if (SelectType::CERTI_LEVEL == modifyType)
			targetInformation->setCertiLevel(modifyInformation->getCertiLevel());
	}

	ProcessResult* modifyEmployeeByEmployeeNumber(int emplyeeNumber, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		processResult_.numOfRecord = fakeDataManager_.count(emplyeeNumber);

		if (processResult_.numOfRecord)
			processResult_.printRecord[0] = to_string(fakeDataManager_.at(emplyeeNumber).getEmployeeNumber());

		//get
		EmployeeInformation info = fakeDataManager_.at(emplyeeNumber);

		//delete
		deleteEmployeeByEmployeeNumber(emplyeeNumber);

		//modify
		modifyEmployeeInformation(modifyType, &info, modifyInformation);

		//add
		addEmployee(info);

		return &processResult_;
	}

	ProcessResult* modifyEmployeeMap(map <string, vector<unsigned int>>& dataManagerMap, string str, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		processResult_.numOfRecord = dataManagerMap[str].size();
		vector<unsigned int> v = dataManagerMap[str];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//get
			EmployeeInformation info = fakeDataManager_.at(*it);

			//delete
			deleteAllMapByEmployeeNumber(*it);

			//modify
			modifyEmployeeInformation(modifyType, &info, modifyInformation);

			//add
			addEmployee(info);
		}

		return &processResult_;
	}

	ProcessResult* modifyEmployeeMap(map <CareerLevel, vector<unsigned int>>& dataManagerMap, CareerLevel careerLevel, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		processResult_.numOfRecord = dataManagerMap[careerLevel].size();
		vector<unsigned int> v = dataManagerMap[careerLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//get
			EmployeeInformation info = fakeDataManager_.at(*it);

			//delete
			deleteAllMapByEmployeeNumber(*it);

			//modify
			modifyEmployeeInformation(modifyType, &info, modifyInformation);

			//add
			addEmployee(info);
		}

		return &processResult_;
	}

	ProcessResult* modifyEmployeeMap(map <unsigned int, vector<unsigned int>>& dataManagerMap, unsigned int searchInt, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		processResult_.numOfRecord = dataManagerMap[searchInt].size();
		vector<unsigned int> v = dataManagerMap[searchInt];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//get
			EmployeeInformation info = fakeDataManager_.at(*it);

			//delete
			deleteAllMapByEmployeeNumber(*it);

			//modify
			modifyEmployeeInformation(modifyType, &info, modifyInformation);

			//add
			addEmployee(info);
		}

		return &processResult_;
	}

	ProcessResult* modifyEmployeeMap(map <CertiLevel, vector<unsigned int>>& dataManagerMap, CertiLevel certiLevel, const SelectType modifyType, EmployeeInformation* modifyInformation)
	{
		processResult_.numOfRecord = dataManagerMap[certiLevel].size();
		vector<unsigned int> v = dataManagerMap[certiLevel];

		sort(v.begin(), v.end(), employeeNumberCompare);

		int i = 0;
		for (auto it = v.begin(); i < 5 && it != v.end(); ++it)
		{
			processResult_.printRecord[i++] = to_string(*it);
		}

		for (auto it = v.begin(); it != v.end(); ++it)
		{
			//get
			EmployeeInformation info = fakeDataManager_.at(*it);

			//delete
			deleteAllMapByEmployeeNumber(*it);

			//modify
			modifyEmployeeInformation(modifyType, &info, modifyInformation);

			//add
			addEmployee(info);
		}

		return &processResult_;
	}

	ProcessResult* getProcessResult() {
		return &processResult_;
	}

	size_t getNumOffakeDataManager()
	{
		return fakeDataManager_.size();
	}

	EmployeeInformation& getEmployeeInformation(unsigned int employeeNumber)
	{
		return fakeDataManager_.at(employeeNumber);
	}

protected:
	map <unsigned int, EmployeeInformation> fakeDataManager_;
	map <string, vector<unsigned int>> fakeDataManagerFullName_;
	map <string, vector<unsigned int>> fakeDataManagerFristName_;
	map <string, vector<unsigned int>> fakeDataManagerLastName_;
	map <CareerLevel, vector<unsigned int>> fakeDataManagerCareerLevel_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerFullPhoneNumber_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerMidPhoneNumber_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerLastPhoneNumber_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerFullBirthDay_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerYearOfBirthday_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerMonthOfBirthday_;
	map <unsigned int, vector<unsigned int>> fakeDataManagerDayOfBirthday_;
	map <CertiLevel, vector<unsigned int>> fakeDataManagerCertiLevel_;

private:
	ProcessResult processResult_;
};


class MockDataManager : public IDataManager {
public:
	MOCK_METHOD(void, addEmployee, (EmployeeInformation& EmployeeInformation), (override));
	MOCK_METHOD(ProcessResult*, deleteEmployee, (const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInformation), (override));
	MOCK_METHOD(ProcessResult*, searchEmployee, (const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation), (override));
	MOCK_METHOD(ProcessResult*, modifyEmployee, (const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation, const SelectType modifyType, EmployeeInformation* modifyInformation), (override));

	void DelegateToFake() {
		ON_CALL(*this, addEmployee).WillByDefault([this](EmployeeInformation& EmployeeInformation) {return fake_.addEmployee(EmployeeInformation); });
		ON_CALL(*this, deleteEmployee).WillByDefault([this](const bool isDetailPrint, const SelectType deleteType, EmployeeInformation& deleteInformation)-> ProcessResult* {return fake_.deleteEmployee(isDetailPrint, deleteType, deleteInformation); });
		ON_CALL(*this, searchEmployee).WillByDefault([this](const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation)-> ProcessResult* {return fake_.searchEmployee(isDetailPrint, searchType, searchInformation); });
		ON_CALL(*this, modifyEmployee).WillByDefault([this](const bool isDetailPrint, const SelectType searchType, EmployeeInformation& searchInformation, const SelectType modifyType, EmployeeInformation* modifyInformation)-> ProcessResult* {return fake_.modifyEmployee(isDetailPrint, searchType, searchInformation, modifyType, modifyInformation); });
	}

	size_t getNumOfFakeDataManager()
	{
		return fake_.getNumOffakeDataManager();
	}

	ProcessResult* getProcessResult()
	{
		return fake_.getProcessResult();
	}

	EmployeeInformation& getEmployeeInformation(unsigned int employeeNumber)
	{
		return fake_.getEmployeeInformation(employeeNumber);
	}
private:
	FakeDataManager fake_;  // Keeps an instance of the fake in the mock.

};