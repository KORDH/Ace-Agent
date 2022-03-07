#pragma once

const unsigned int EMPLOYEE_NUM_BOUND = 22000000;
const unsigned int EMPLOYEE_NUM_CORRECTION = 100000000;

enum class Command
{
	INVALID,
	ADD,
	DEL,
	SCH,
	MOD,
};

enum class SelectType
{
	EMPLOYEE_NUMBER,
	FULL_NAME,
	FIRST_NAME,
	LAST_NAME,
	CAREER_LEVEL,
	FULL_PHONE_NUMBER,
	MID_PHONE_NUMBER,
	LAST_PHONE_NUMBER,
	FULL_BIRTHDAY,
	YEAR_OF_BIRTHDAY,
	MONTH_OF_BIRTHDAY,
	DAY_OF_BIRTHDAY,
	CERTI_LEVEL,
	NONE
};
