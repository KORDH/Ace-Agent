#include "pch.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../AceAgent/CommandHandler.h"

bool isFileSame(string fileName1, string fileName2)
{
    ifstream file1(fileName1);
    ifstream file2(fileName2);

    string str1;
    string str2;

    while (!file1.eof())
    {
        getline(file1, str1);
        getline(file2, str2);

        if (str1 != str2)
        {
            return false;
        }
    }

    if (!file2.eof())  return false;

    return true;
}

TEST(mainUnitest, providedInput)
{
	auto commandHandler{ new CommandHandler };

	string outputFile = "../AceAgent/output.txt";
	string outputFile_Answer = "../AceAgent/output_answer.txt";

	commandHandler->Run("../AceAgent/input.txt", outputFile);

	EXPECT_EQ(isFileSame(outputFile, outputFile_Answer), true);
}

TEST(mainUnitest, EmployeeNumberCase)
{
    auto commandHandler{ new CommandHandler };

    string outputFile = "../AceAgent/output2.txt";
    string outputFile_Answer = "../AceAgent/output_answer2.txt";

    commandHandler->Run("../AceAgent/input2.txt", outputFile);

    EXPECT_EQ(isFileSame(outputFile, outputFile_Answer), false);
}

TEST(mainUnitest, allNoneCase)
{
    auto commandHandler{ new CommandHandler };

    string outputFile = "../AceAgent/output3.txt";
    string outputFile_Answer = "../AceAgent/output_answer3.txt";

    commandHandler->Run("../AceAgent/input3.txt", outputFile);

    EXPECT_EQ(isFileSame(outputFile, outputFile_Answer), false);
}

TEST(mainUnitest, largeInputCase)
{
    auto commandHandler{ new CommandHandler };

    string outputFile = "../AceAgent/output4.txt";
    string outputFile_Answer = "../AceAgent/output_answer4.txt";

    commandHandler->Run("../AceAgent/input4.txt", outputFile);

    EXPECT_EQ(isFileSame(outputFile, outputFile_Answer), false);
}