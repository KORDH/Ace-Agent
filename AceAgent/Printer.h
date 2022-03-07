#pragma once

#include "ProcessResult.h"
#include <iostream>

using namespace std;

class Printer
{
public: 
	Printer()
	{
	}

	string printRecord(bool isDetailPrint, ProcessResult processResult, string commandStr)
	{
		string result = "";
		if (isDetailPrint)
		{
			for (string record : processResult.printRecord)
				result += record + "\n";
		}
		else
		{
			result += "commandStr," + processResult.numOfRecord;
			result += "\n";
		}
		return result;

	}
private:
};