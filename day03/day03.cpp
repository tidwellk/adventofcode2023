/*
--- Day 3: Gear Ratios ---

You and the Elf eventually reach a gondola lift station; he says the gondola lift will take you up to the water source, but this is as far as he can bring you. You go inside.

It doesn't take long to find the gondolas, but there seems to be a problem: they're not moving.

"Aaah!"

You turn around to see a slightly-greasy Elf with a wrench and a look of surprise. "Sorry, I wasn't expecting anyone! The gondola lift isn't working right now; it'll still be a while before I can fix it." You offer to help.

The engineer explains that an engine part seems to be missing from the engine, but nobody can figure out which one. If you can add up all the part numbers in the engine schematic, it should be easy to work out which part is missing.

The engine schematic (your puzzle input) consists of a visual representation of the engine. There are lots of numbers and symbols you don't really understand, but apparently any number adjacent to a symbol, even diagonally, is a "part number" and should be included in your sum. (Periods (.) do not count as a symbol.)

Here is an example engine schematic:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..

In this schematic, two numbers are not part numbers because they are not adjacent to a symbol: 114 (top right) and 58 (middle right). Every other number is adjacent to a symbol and so is a part number; their sum is 4361.

Of course, the actual engine schematic is much larger. What is the sum of all of the part numbers in the engine schematic?

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

bool isDigit(char myChar)
{
    if (myChar < '0')
    {
        return false;
    }

    if (myChar > '9')
    {
        return false;
    }

    return true;
}

int main()
{
    std::string filename = "testinput.txt";
    std::ifstream myFile;
    myFile.open(filename);

    if (!myFile.is_open())
    {
        std::cout << "cant open file " << filename << std::endl;
        exit(1);
    }

    int sum = 0;

    std::string line;
    std::vector<std::vector<char>> myLines;

    while (getline(myFile, line))
    {
        std::cout << line << std::endl;
        std::vector<char> newLineOfChars;

        for (size_t i = 0; i < line.length(); i++)
        {
            newLineOfChars.push_back(line.at(i));
        }
        myLines.push_back(newLineOfChars);
    }

    // std::vector<std::string> numsWithSurroundings;
    int numberOfRows = myLines.size();
    int numberOfColumns = myLines.at(0).size();

    for (size_t lineIndex = 0; lineIndex < myLines.size(); lineIndex++)
    {
        for (size_t charIndex = 0; charIndex < myLines.at(0).size(); charIndex++)
        {
            std::vector<std::string> listOfNumbers;

            std::string newPartString = "";

            std::cout << myLines[lineIndex][charIndex] << std::endl;
            bool isPartNumber = false;
            char myChar = myLines[lineIndex][charIndex];
            while (isDigit(myChar))
            {
                
            }
            if (isDigit(myChar))
            {
                newPartString += myChar;
            }
        }
    }

    // std::cout << "sum: " << c << std::endl;
}
