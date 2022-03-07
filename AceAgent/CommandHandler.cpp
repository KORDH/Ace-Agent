#include "CommandHandler.h"
#include "CommandParser.h"
#include "CommandProcessor.h"
#include "operator.h"
#include <fstream>
#include <string>

static string temp_string_Answer =
"SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\n\
MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO\n\
SCH,NONE\n\
DEL,1\n\
DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV\n\
SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\n\
SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\n\
SCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO\n\
SCH,6\n\
SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO\n\
SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\n\
SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV\n\
SCH,1\n\
MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO\n\
MOD,08123556,WN XV,CL1,010-7986-5047,20100614,PRO\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO\n\
SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO\n\
SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV\n\
SCH,NONE\n\
SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV\n\
MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV\n\
SCH,NONE\n\
MOD,1\n\
SCH,1";

void
CommandHandler::Run(string input, string output)
{
    ifstream inputFile(input);
    ofstream outputFile(output);

    if (inputFile.fail()) exit(EXIT_FAILURE);

    CommandParser* parser{ new CommandParser() };

    string answer = "";
    IDataManager* iDataManager = new Operator();
    Printer* printer = new Printer();
	AddCommandProcessor* addCommandProcessor = new AddCommandProcessor(*iDataManager);
	DeleteCommandProcessor* deleteCommandProcessor = new DeleteCommandProcessor(*iDataManager);
	SearchCommandProcessor* searchCommandProcessor = new SearchCommandProcessor(*iDataManager);
	ModifyCommandProcessor* modifyCommandProcessor = new ModifyCommandProcessor(*iDataManager);

    while (!inputFile.eof())
    {
        string commandLine;
        getline(inputFile, commandLine);

        ParseInfo parseInfo;
        parser->parseCommandLine(commandLine, parseInfo);

        /* Call CommandProcessor */
        switch (parseInfo.command)
        {
        case Command::ADD:
            addCommandProcessor->runCommand(parseInfo.employee);
            break;
        case Command::DEL:
            deleteCommandProcessor->setDeleteInformation(parseInfo.isDetailPrint, parseInfo.searchType);
            deleteCommandProcessor->runCommand(parseInfo.employee);
            answer+=printer->printRecord(parseInfo.isDetailPrint, deleteCommandProcessor->getProcessResult(), "DEL");
            break;

        case Command::SCH:
            searchCommandProcessor->setSearchInformation(parseInfo.isDetailPrint, parseInfo.searchType);
            searchCommandProcessor->runCommand(parseInfo.employee);
            answer += printer->printRecord(parseInfo.isDetailPrint, searchCommandProcessor->getProcessResult(), "SCH");
            break;

        case Command::MOD:
            modifyCommandProcessor->setModifyInformation(parseInfo.isDetailPrint, parseInfo.searchType,parseInfo.modifyType,parseInfo.modifyEmployee);
            modifyCommandProcessor->runCommand(parseInfo.employee);
            answer += printer->printRecord(parseInfo.isDetailPrint, modifyCommandProcessor->getProcessResult(), "MOD");
            break;
        default:
            break;
        }
    }
    outputFile << answer;

    inputFile.close();
    outputFile.close();
}