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
			int cnt = 0;
			for (string record : processResult.printRecord)
			{
				if (cnt >= 5)
					break;

				result += record + "\n";
				cnt++;

			}
		}
		else
		{
			string numOfRecord = processResult.numOfRecord ? to_string(processResult.numOfRecord) : "NONE";
			result.append(commandStr).append(",").append(numOfRecord).append("\n");
		}
		return result;

	}
private:
};