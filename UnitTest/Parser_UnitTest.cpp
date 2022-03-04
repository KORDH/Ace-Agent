#include "pch.h"
#include "../AceAgent/CommandParser.h"

TEST(ParserUnitest, ParsingADD) 
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::ADD;
	parseInfo_Answer.employee.employeeNumber = 15123099;
	parseInfo_Answer.employee.name.first = "VXIHXOTH";
	parseInfo_Answer.employee.name.last = "JHOP";
	parseInfo_Answer.employee.careerLevel = CareerLevel::CL3;
	parseInfo_Answer.employee.phoneNumber = { 3112, 2609 };
	parseInfo_Answer.employee.birthday = { 1977, 12, 11 };
	parseInfo_Answer.employee.certiLevel = CertiLevel::ADV;

	string commandLine = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingDEL_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::DEL;
	parseInfo_Answer.searchType = SelectType::EMPLOYEE_NUMBER;
	parseInfo_Answer.employee.employeeNumber = 18115040;

	string commandLine = "DEL, , , ,employeeNum,18115040";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingDEL_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::DEL;
	parseInfo_Answer.isDetailPrint = true;
	parseInfo_Answer.searchType = SelectType::LAST_NAME;
	parseInfo_Answer.employee.name.last = "MPOSXU";

	string commandLine = "DEL,-p,-l, ,name,MPOSXU";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingSCH_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::SCH;
	parseInfo_Answer.searchType = SelectType::CERTI_LEVEL;
	parseInfo_Answer.employee.certiLevel = CertiLevel::ADV;

	string commandLine = "SCH, , , ,certi,ADV";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingSCH_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::SCH;
	parseInfo_Answer.searchType = SelectType::MONTH_OF_BIRTHDAY;
	parseInfo_Answer.employee.birthday.month = 9;

	string commandLine = "SCH, ,-m, ,birthday,09";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingMOD_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::MOD;
	parseInfo_Answer.searchType = SelectType::EMPLOYEE_NUMBER;
	parseInfo_Answer.employee.employeeNumber = 8123556;
	parseInfo_Answer.modifyType = SelectType::BIRTHDAY;
	parseInfo_Answer.modifyEmployee.birthday = { 2011,7, 6 };

	string commandLine = "MOD, , , ,employeeNum,08123556,birthday,20110706";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}

TEST(ParserUnitest, ParsingMOD_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::MOD;
	parseInfo_Answer.searchType = SelectType::LAST_NAME;
	parseInfo_Answer.employee.name.last = "KIM";
	parseInfo_Answer.modifyType = SelectType::PHONE_NUMBER;
	parseInfo_Answer.modifyEmployee.phoneNumber = { 9777, 5455 };

	string commandLine = "MOD, ,-l, ,name,KIM,phoneNum,010-9777-5455";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber, parseInfo.employee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.employee.name.first, parseInfo.employee.name.first);
	EXPECT_EQ(parseInfo_Answer.employee.name.last, parseInfo.employee.name.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel, parseInfo.employee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.mid, parseInfo.employee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber.last, parseInfo.employee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.year, parseInfo.employee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.month, parseInfo.employee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.employee.birthday.day, parseInfo.employee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel, parseInfo.employee.certiLevel);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber, parseInfo.modifyEmployee.employeeNumber);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.first, parseInfo.modifyEmployee.name.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name.last, parseInfo.modifyEmployee.name.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel, parseInfo.modifyEmployee.careerLevel);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.mid, parseInfo.modifyEmployee.phoneNumber.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber.last, parseInfo.modifyEmployee.phoneNumber.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.year, parseInfo.modifyEmployee.birthday.year);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.month, parseInfo.modifyEmployee.birthday.month);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday.day, parseInfo.modifyEmployee.birthday.day);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel, parseInfo.modifyEmployee.certiLevel);
}