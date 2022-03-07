#include <fstream>
#include <string>
#include <iostream>
#include "CommandHandler.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        cerr << "[Error] Usage: " << argv[0] << " input_file output_file" << endl;

        exit(EXIT_FAILURE);
    }

    auto commandHandler{ new CommandHandler };
    commandHandler->Run(argv[1], argv[2]);

    return EXIT_SUCCESS;
}