#pragma once

#include "ProcessResult.h"
#include <iostream>

using namespace std;

class Printer
{
public: 
	Printer(string command) : command_{ command }
	{}

	void printRecord(bool isDetailPrint, ProcessResult& processResult)
	{
		if (isDetailPrint)
		{
			for (string result : processResult.printRecord)
				cout << result << endl;
		}
		else
			cout << processResult.numOfRecord << endl;

	}
private:
	string command_;
};