/*
--- Day 1: Trebuchet?! ---

Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.

You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").

As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to show off her art skills. Consequently, the Elves are having trouble reading the values on the document.

The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover. On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?

*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

/// @brief Returns true if the char is a number
/// @param myChar
/// @return
bool isDigit(char myChar)
{
    if (myChar >= '0' && myChar <= '9')
    {
        return true;
    }

    return false;
}

char findFirst(std::string line)
{
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isDigit(line.at(i)))
        {
            return line.at(i);
        }
    }
}

int main()
{
    std::map<std::string, int> fiveLetters;
    fiveLetters["three"] = 3;
    fiveLetters["seven"] = 7;
    fiveLetters["eight"] = 8;

    std::map<std::string, int> fourLetters;
    fourLetters["four"] = 4;
    fourLetters["five"] = 5;
    fourLetters["nine"] = 9;

    std::map<std::string, int> threeLetters;
    threeLetters["one"] = 1;
    threeLetters["two"] = 2;
    threeLetters["six"] = 6;

    std::string filename = "puzzleInput.txt";
    std::ifstream myFile;
    myFile.open(filename);

    if (!myFile.is_open())
    {
        std::cout << "cant open file " << filename << std::endl;
        exit(1);
    }

    int sum = 0;
    int sumold = 0;

    std::string line;
    while (getline(myFile, line))
    {
        char firstDigit;
        char lastDigit;

        //       std::cout << std::endl;
        //      std::cout << line << std::endl;

        std::string oldLine(line);
        int lineLength = line.length();
        // find first digit
        size_t lineIndex = 0;
        while (!isDigit(line.at(lineIndex)))
        {
            lineIndex++;
        }
        firstDigit = line.at(lineIndex);

        // find last digit
        lineIndex = line.length() - 1;
        while (!isDigit(line.at(lineIndex)))
        {
            lineIndex--;
        }
        lastDigit = line.at(lineIndex);

        std::string twoDigitsOld{firstDigit, lastDigit};
        sumold += stoi(twoDigitsOld);
        // std::cout << twoDigitsOld << std::endl;

        if (line.at(0) == 'v')
        {
            std::string hello = "hello";
        }

        // replace the spelled out words with digits
        for (size_t index = 0; index < line.length(); index++)
        {
            char curChar = line.at(index);

            // 2
            if (line.at(index) == 't')
            {
                if (index + 2 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'w' &&
                    line.at(index + 2) == 'o')
                {
                    line.replace(index, 3, "2wo");
                    continue;
                }
            }

            // 1
            if (line.at(index) == 'o')
            {
                if (index + 2 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'n' &&
                    line.at(index + 2) == 'e')
                {
                    line.replace(index, 3, "1ne");
                    continue;
                }
            }

            // six
            if (line.at(index) == 's')
            {
                if (index + 2 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'i' &&
                    line.at(index + 2) == 'x')
                {
                    line.replace(index, 3, "6ix");
                    continue;
                }
            }

            // nine
            if (line.at(index) == 'n')
            {
                if (index + 3 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'i' &&
                    line.at(index + 2) == 'n' &&
                    line.at(index + 3) == 'e')
                {
                    line.replace(index, 4, "9ine");
                    continue;
                }
            }

            // 5
            if (line.at(index) == 'f')
            {
                if (index + 3 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'i' &&
                    line.at(index + 2) == 'v' &&
                    line.at(index + 3) == 'e')
                {
                    line.replace(index, 4, "5ive");
                    continue;
                }
            }

            // 4
            if (line.at(index) == 'f')
            {
                if (index + 3 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'o' &&
                    line.at(index + 2) == 'u' &&
                    line.at(index + 3) == 'r')
                {
                    line.replace(index, 4, "4our");
                    continue;
                }
            }

            // eight
            if (line.at(index) == 'e')
            {
                if (index + 4 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'i' &&
                    line.at(index + 2) == 'g' &&
                    line.at(index + 3) == 'h' &&
                    line.at(index + 4) == 't')
                {
                    line.replace(index, 5, "8ight");
                    continue;
                }
            }

            // seven
            if (line.at(index) == 's')
            {
                if (index + 4 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'e' &&
                    line.at(index + 2) == 'v' &&
                    line.at(index + 3) == 'e' &&
                    line.at(index + 4) == 'n')
                {
                    line.replace(index, 5, "7even");
                    continue;
                }
            }

            // three
            if (line.at(index) == 't')
            {
                if (index + 4 >= line.length())
                {
                    continue;
                }

                if (line.at(index + 1) == 'h' &&
                    line.at(index + 2) == 'r' &&
                    line.at(index + 3) == 'e' &&
                    line.at(index + 4) == 'e')
                {
                    line.replace(index, 5, "3hree");
                    continue;
                }
            }
        }
        //        std::cout << line << std::endl;

        // find first digit
        lineIndex = 0;
        while (!isDigit(line.at(lineIndex)))
        {
            lineIndex++;
        }
        firstDigit = line.at(lineIndex);

        // find last digit
        lineIndex = line.length() - 1;
        while (!isDigit(line.at(lineIndex)))
        {
            lineIndex--;
        }
        lastDigit = line.at(lineIndex);

        std::string twoDigits{firstDigit, lastDigit};
        // std::cout << twoDigits << std::endl;
        int twoDigitNumberOld = stoi(twoDigitsOld);
        int twoDigitNumber = stoi(twoDigits);

        if (twoDigitNumberOld != twoDigitNumber)
        {
            std::cout << oldLine << "\t" << twoDigitsOld << std::endl;
            std::cout << line << "\t" << twoDigits << std::endl;
            std::cout << oldLine << "\t" << twoDigits << std::endl;
            if (twoDigitNumber == 18)
            {
                // std::string tempInput;
                // std::cin >> tempInput;
            }
        }

        sum += twoDigitNumber;
    }

    std::cout << "old sum: " << sumold << std::endl;
    std::cout << "sum    : " << sum << std::endl;
}
