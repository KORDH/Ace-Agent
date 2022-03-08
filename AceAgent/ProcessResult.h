#pragma once
#include <vector>
#include <string>
using namespace std;

class ProcessResult
{
public:
	vector<string> printRecord;
	unsigned int numOfRecord = 0;

	ProcessResult& operator = (const ProcessResult& p)
	{
		numOfRecord = p.numOfRecord;
		printRecord.clear();
		for (auto it = p.printRecord.begin(); it != p.printRecord.end(); it++)
			printRecord.push_back(*it);
		return *this;
	}
};
