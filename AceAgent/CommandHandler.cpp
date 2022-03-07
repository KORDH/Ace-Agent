#include "CommandHandler.h"
#include "CommandParser.h"
#include <fstream>
#include <string>

void
CommandHandler::Run(ifstream& inputFile)
{
    CommandParser* parser{ new CommandParser() };

    while (!inputFile.eof())
    {
        string commandLine;
        getline(inputFile, commandLine);

        ParseInfo parseInfo;
        parser->parseCommandLine(commandLine, parseInfo);

        /* Call CommandProcessor */       
    }
}