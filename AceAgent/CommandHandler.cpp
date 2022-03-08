#include "CommandHandler.h"
#include "CommandParser.h"
#include "CommandProcessor.h"
#include "operator.h"
#include <fstream>
#include <string>

void
CommandHandler::Run(string input, string output)
{
    ifstream inputFile(input);
    ofstream outputFile(output);

    if (inputFile.fail()) exit(EXIT_FAILURE);

    IOperator* iOperator = new Operator();
    Printer* printer = new Printer();
	AddCommandProcessor* addCommandProcessor = new AddCommandProcessor(*iOperator);
	DeleteCommandProcessor* deleteCommandProcessor = new DeleteCommandProcessor(*iOperator);
	SearchCommandProcessor* searchCommandProcessor = new SearchCommandProcessor(*iOperator);
	ModifyCommandProcessor* modifyCommandProcessor = new ModifyCommandProcessor(*iOperator);

    while (!inputFile.eof())
    {
        string commandLine;
        getline(inputFile, commandLine);

        CommandParser* parser{ new CommandParser() };
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
            outputFile << printer->printRecord(parseInfo.isDetailPrint, deleteCommandProcessor->getProcessResult(), "DEL");
            break;

        case Command::SCH:
            searchCommandProcessor->setSearchInformation(parseInfo.isDetailPrint, parseInfo.searchType);
            searchCommandProcessor->runCommand(parseInfo.employee);
            outputFile << printer->printRecord(parseInfo.isDetailPrint, searchCommandProcessor->getProcessResult(), "SCH");
            break;

        case Command::MOD:
            modifyCommandProcessor->setModifyInformation(parseInfo.isDetailPrint, parseInfo.searchType,parseInfo.modifyType,parseInfo.modifyEmployee);
            modifyCommandProcessor->runCommand(parseInfo.employee);
            outputFile << printer->printRecord(parseInfo.isDetailPrint, modifyCommandProcessor->getProcessResult(), "MOD");
            break;
        default:
            break;
        }
    }

    inputFile.close();
    outputFile.close();
}