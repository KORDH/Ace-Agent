#include "RecordMaker.h"

vector<string> cmdTypeName = { "INVALID", "ADD", "DEL", "SCH", "MOD" };
vector<string> careerLevelName = { "CL1", "CL2", "CL3", "CL4" };
vector<string> certiLevelName = { "ADV", "PRO", "EX" };

vector<string>
RecordMaker::makeRecord(bool isDetailPrint, Command cmdType, vector<EmployeeInformation> employeeInfoList)
{
    vector<string> result;

    if (employeeInfoList.size() == 0)
    {
        string record = cmdTypeName[(int)cmdType] + ",NONE";
        result.push_back(record);

        return result;
    }

    if (isDetailPrint)
    {
        for (auto it : employeeInfoList)
        {
            string record = cmdTypeName[(int)cmdType] + ",";

            stringstream employeeNumStream;
            employeeNumStream.width(8);
            employeeNumStream.fill('0');
            employeeNumStream << ((it.employeeNumber_ > EMPLOYEE_NUM_CORRECTION) ? (it.employeeNumber_ - EMPLOYEE_NUM_CORRECTION) : it.employeeNumber_);

            stringstream monthOfBirth;
            monthOfBirth.width(2);
            monthOfBirth.fill('0');
            monthOfBirth << it.birthday_.month_;

            stringstream dayOfBirth;
            dayOfBirth.width(2);
            dayOfBirth.fill('0');
            dayOfBirth << it.birthday_.day_;

            record += employeeNumStream.str() + "," +
                it.name_.first + " " + it.name_.last + "," +
                careerLevelName[(int)(it.careerLevel_)] + "," +
                "010-" + to_string(it.phoneNumber_.mid) + "-" + to_string(it.phoneNumber_.last) + "," +
                to_string(it.birthday_.year_) + monthOfBirth.str() + dayOfBirth.str() + "," +
                certiLevelName[(int)(it.certiLevel_)];

            result.push_back(record);
        }
    }
    else
    {
        string record = cmdTypeName[(int)cmdType] + "," + to_string(employeeInfoList.size());
        result.push_back(record);
    }

    return result;
}
