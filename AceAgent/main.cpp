#include <fstream>
#include <string>
#include "CommandHandler.h"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inputFile("input.txt");

    if (inputFile.fail())  exit(1);

    auto commandHandler{ new CommandHandler };
    commandHandler->Run(inputFile);

    inputFile.close();
    return 0;
}