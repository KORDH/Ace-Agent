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
		printRecord.assign(p.printRecord.begin(), p.printRecord.end());
		return *this;
	}
};
