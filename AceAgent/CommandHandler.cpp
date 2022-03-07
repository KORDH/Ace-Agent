#include "CommandHandler.h"
#include "CommandParser.h"
#include <fstream>
#include <string>

void
CommandHandler::Run(string input, string output)
{
    ifstream inputFile(input);
    ofstream outputFile(output);

    if (inputFile.fail()) exit(EXIT_FAILURE);

    CommandParser* parser{ new CommandParser() };

    while (!inputFile.eof())
    {
        string commandLine;
        getline(inputFile, commandLine);

        ParseInfo parseInfo;
        parser->parseCommandLine(commandLine, parseInfo);

        /* Call CommandProcessor */
    }

    inputFile.close();
    outputFile.close();
}