#pragma once

#include "pch.h"
#include "MockDataManager.h"
#include "../AceAgent/CommandProcessor.h"

class FixtureCommandProcessor : public ::testing::Test {
protected:
	void SetUp() override {
		mockProcessor_.DelegateToFake();
		mockProcessor_.addEmployee(*(new EmployeeInformation(15123099, "VXIHXOTH", "JHOP", CareerLevel::CL3, 3112, 2609, 1977, 12, 11, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(17112609, "FB", "NTAWR", CareerLevel::CL4, 5645, 6122, 1986, 12, 3, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(18115040, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, 2008, 7, 18, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(88114052, "NQ", "LVARW", CareerLevel::CL4, 4528, 3059, 1991, 10, 21, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(19129568, "SRERLALH", "HMEF", CareerLevel::CL2, 3091, 9521, 1964, 9, 10, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(17111236, "VSID", "TVO", CareerLevel::CL1, 3669, 1077, 2012, 7, 18, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(18117906, "TWU", "QSOLT", CareerLevel::CL4, 6672, 7186, 2003, 4, 13, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(8123556, "WN", "XV", CareerLevel::CL1, 7986, 5047, 2010, 6, 14, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(2117175, "SBILHUT", "LDEXRI", CareerLevel::CL4, 2814, 1699, 1995, 7, 4, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(3113260, "HH", "LTUPF", CareerLevel::CL2, 5798, 5383, 1979, 10, 18, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(14130827, "RPO", "JK", CareerLevel::CL4, 3231, 1698, 2009, 2, 1, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(1122329, "DN", "WD", CareerLevel::CL4, 7174, 5680, 2007, 11, 17, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(8108827, "RTAH", "VNUP", CareerLevel::CL4, 9031, 2726, 1978, 4, 17, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(85125741, "FBAH", "RTIJ", CareerLevel::CL1, 8900, 1478, 1978, 2, 28, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(8117441, "BMU", "MPOSXU", CareerLevel::CL3, 2703, 3153, 2001, 2, 15, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(10127115, "KBU", "MHU", CareerLevel::CL3, 3284, 4054, 1966, 8, 14, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(12117017, "LFIS", "JJIVL", CareerLevel::CL1, 7914, 4067, 2012, 8, 12, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(11125777, "TKOQKIS", "HC", CareerLevel::CL1, 6734, 2289, 1999, 10, 1, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(11109136, "QKAHCEX", "LTODDO", CareerLevel::CL4, 2627, 8566, 1964, 1, 30, CertiLevel::PRO)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(5101762, "VCUHLE", "HMU", CareerLevel::CL4, 3988, 9289, 2003, 8, 19, CertiLevel::PRO)));
		
		//Full name 중복 데이터
		mockProcessor_.addEmployee(*(new EmployeeInformation(18115041, "TTETHU", "HBO", CareerLevel::CL3, 4581, 2050, 2008, 7, 18, CertiLevel::ADV)));

		//First name 중복 데이터
		mockProcessor_.addEmployee(*(new EmployeeInformation(18115042, "TTETHU", "KIM", CareerLevel::CL3, 4582, 2050, 2008, 7, 18, CertiLevel::ADV)));

		//Last name 중복 데이터
		mockProcessor_.addEmployee(*(new EmployeeInformation(18115043, "ABC", "HBO", CareerLevel::CL3, 4581, 2051, 2008, 7, 18, CertiLevel::ADV)));
		mockProcessor_.addEmployee(*(new EmployeeInformation(18115044, "DEF", "HBO", CareerLevel::CL3, 4582, 2051, 2008, 7, 18, CertiLevel::ADV)));
	
	}

	void TearDown() override {
	}

public:
	testing::NiceMock<MockDataManager> mockProcessor_;
};