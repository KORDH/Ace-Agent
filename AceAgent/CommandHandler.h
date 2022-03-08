#pragma once
#include <string>
using namespace std;

class CommandHandler
{
public:
	void Run(string inputFile, string ofstream);

private:
	static constexpr unsigned int MINIMUN_COMMAND_LINE_SIZE = 5;
};