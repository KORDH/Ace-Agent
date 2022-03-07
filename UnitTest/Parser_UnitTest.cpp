#include "pch.h"
#include "../AceAgent/CommandParser.h"

TEST(ParserUnitest, ParsingADD) 
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::ADD;
	parseInfo_Answer.employee.employeeNumber_ = 15123099;
	parseInfo_Answer.employee.name_.first = "VXIHXOTH";
	parseInfo_Answer.employee.name_.last = "JHOP";
	parseInfo_Answer.employee.careerLevel_ = CareerLevel::CL3;
	parseInfo_Answer.employee.phoneNumber_ = { 3112, 2609 };
	parseInfo_Answer.employee.birthday_ = { 1977, 12, 11 };
	parseInfo_Answer.employee.certiLevel_ = CertiLevel::ADV;

	string commandLine = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingDEL_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::DEL;
	parseInfo_Answer.searchType = SelectType::EMPLOYEE_NUMBER;
	parseInfo_Answer.employee.employeeNumber_ = 18115040;

	string commandLine = "DEL, , , ,employeeNum,18115040";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingDEL_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::DEL;
	parseInfo_Answer.isDetailPrint = true;
	parseInfo_Answer.searchType = SelectType::LAST_NAME;
	parseInfo_Answer.employee.name_.last = "MPOSXU";

	string commandLine = "DEL,-p,-l, ,name,MPOSXU";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingSCH_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::SCH;
	parseInfo_Answer.searchType = SelectType::CERTI_LEVEL;
	parseInfo_Answer.employee.certiLevel_ = CertiLevel::ADV;

	string commandLine = "SCH, , , ,certi,ADV";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingSCH_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::SCH;
	parseInfo_Answer.searchType = SelectType::MONTH_OF_BIRTHDAY;
	parseInfo_Answer.employee.birthday_.month_ = 9;

	string commandLine = "SCH, ,-m, ,birthday,09";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingMOD_default)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::MOD;
	parseInfo_Answer.searchType = SelectType::EMPLOYEE_NUMBER;
	parseInfo_Answer.employee.employeeNumber_ = 8123556;
	parseInfo_Answer.modifyType = SelectType::FULL_BIRTHDAY;
	parseInfo_Answer.modifyEmployee.birthday_ = { 2011,7, 6 };

	string commandLine = "MOD, , , ,employeeNum,08123556,birthday,20110706";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}

TEST(ParserUnitest, ParsingMOD_optional)
{
	CommandParser* parser{ new CommandParser() };
	ParseInfo parseInfo;
	ParseInfo parseInfo_Answer;

	parseInfo_Answer.command = Command::MOD;
	parseInfo_Answer.searchType = SelectType::LAST_NAME;
	parseInfo_Answer.employee.name_.last = "KIM";
	parseInfo_Answer.modifyType = SelectType::FULL_PHONE_NUMBER;
	parseInfo_Answer.modifyEmployee.phoneNumber_ = { 9777, 5455 };

	string commandLine = "MOD, ,-l, ,name,KIM,phoneNum,010-9777-5455";

	parser->parseCommandLine(commandLine, parseInfo);

	EXPECT_EQ(parseInfo_Answer.command, parseInfo.command);
	EXPECT_EQ(parseInfo_Answer.isDetailPrint, parseInfo.isDetailPrint);
	EXPECT_EQ(parseInfo_Answer.searchType, parseInfo.searchType);
	EXPECT_EQ(parseInfo_Answer.modifyType, parseInfo.modifyType);

	EXPECT_EQ(parseInfo_Answer.employee.employeeNumber_, parseInfo.employee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.employee.name_.first, parseInfo.employee.name_.first);
	EXPECT_EQ(parseInfo_Answer.employee.name_.last, parseInfo.employee.name_.last);
	EXPECT_EQ(parseInfo_Answer.employee.careerLevel_, parseInfo.employee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.mid, parseInfo.employee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.employee.phoneNumber_.last, parseInfo.employee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.year_, parseInfo.employee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.month_, parseInfo.employee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.employee.birthday_.day_, parseInfo.employee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.employee.certiLevel_, parseInfo.employee.certiLevel_);

	EXPECT_EQ(parseInfo_Answer.modifyEmployee.employeeNumber_, parseInfo.modifyEmployee.employeeNumber_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.first, parseInfo.modifyEmployee.name_.first);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.name_.last, parseInfo.modifyEmployee.name_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.careerLevel_, parseInfo.modifyEmployee.careerLevel_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.mid, parseInfo.modifyEmployee.phoneNumber_.mid);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.phoneNumber_.last, parseInfo.modifyEmployee.phoneNumber_.last);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.year_, parseInfo.modifyEmployee.birthday_.year_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.month_, parseInfo.modifyEmployee.birthday_.month_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.birthday_.day_, parseInfo.modifyEmployee.birthday_.day_);
	EXPECT_EQ(parseInfo_Answer.modifyEmployee.certiLevel_, parseInfo.modifyEmployee.certiLevel_);
}