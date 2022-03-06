#include "RecordMaker.h"

vector<string> cmdTypeName = { "ADD", "DEL", "SCH", "MOD" };
vector<string> careerLevelName = { "CL1", "CL2", "CL3", "CL4" };
vector<string> certiLevelName = { "ADV", "PRO", "EX" };

vector<string>
RecordMaker::makeRecord(bool isDetailPrint, int searchCnt, CmdType cmdType, vector<EmployeeInformation> employeeInfoList)
{
    vector<string> result;

    if (isDetailPrint)
    {
        for (auto it : employeeInfoList)
        {
            string record = cmdTypeName[(int)cmdType] + ",";

            stringstream employeeNumStream;
            employeeNumStream.width(8);
            employeeNumStream.fill('0');
            employeeNumStream << it.employeeNumber;

            record += employeeNumStream.str() + "," +
                it.firstName + " " + it.lastName + "," +
                careerLevelName[(int)(it.careerLevel)] + "," +
                "010-" + to_string(it.midPhoneNumber) + "-" + to_string(it.lastPhoneNumber) + "," +
                to_string(it.birthday.year) + to_string(it.birthday.month) + to_string(it.birthday.day) + "," +
                certiLevelName[(int)(it.certiLevel)];

            result.push_back(record);
        }
    }
    else
    {
        string record = cmdTypeName[(int)cmdType] + "," + to_string(searchCnt);
        result.push_back(record);
    }

    return result;
}
