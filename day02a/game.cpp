#include "game.h"
#include <iostream>

Game::Game(std::string line)
{
    std::stringstream mystream(line);

    std::vector<std::string> currentLineElements;
    std::string currentToken;
    while (getline(mystream, currentToken, ':'))
    {
        currentLineElements.push_back(currentToken);
  //      std::cout << currentToken << std::endl;
    }

    std::string gameNumberString = currentLineElements.front();
    gameNumberString.erase(0, 5);

    this->gameNumber = stoi(gameNumberString);

    std::stringstream roundstream(currentLineElements.back());
    std::string currentRound;
    while (getline(roundstream, currentRound, ';'))
    {
        std::stringstream splitBySpaces(currentRound);
        std::string spaceToken;

        std::vector<std::string> roundElements;
        while (getline(splitBySpaces, spaceToken, ' '))
        {
            if (spaceToken == "")
            {
                continue;
            }

            std::string spaceTokenNoComma = removeCommas(spaceToken);

            roundElements.push_back(spaceTokenNoComma);
        }

        // now i can build the map for this round
        std::map<std::string, int> currentRoundMap;
        for (size_t i = 0; i < roundElements.size(); i += 2)
        {
            std::string numberOfCubesString = roundElements.at(i);
            std::string colorOfCubes = roundElements.at(i + 1);

            int numberOfCubes = stoi(numberOfCubesString);

            currentRoundMap.emplace(colorOfCubes, numberOfCubes);
        }
        listOfRounds.push_back(currentRoundMap);
    }
}

int Game::getGameNumber()
{
    return this->gameNumber;
}

std::string Game::removeCommas(std::string oldString)
{
    std::string newString(oldString);

    for (size_t index = 0; index < newString.length(); index++)
    {
        if (newString.at(index) == ',')
        {
            newString.replace(index, 1, "");
        }
    }

    return newString;
}

bool Game::isPossible(int redmax, int greenmax, int bluemax)
{
    for (std::map<std::string, int> currentRound : listOfRounds)
    {
        if (currentRound.contains("red"))
        {
            if (currentRound["red"] > redmax)
            {
                return false;
            }
        }
        if (currentRound.contains("green"))
        {
            if (currentRound["green"] > greenmax)
            {
                return false;
            }
        }
        if (currentRound.contains("blue"))
        {
            if (currentRound["blue"] > bluemax)
            {
                return false;
            }
        }
    }

    return true;
}

std::vector<int> Game::minimumNumberOfCubes()
{
    std::vector<int> minCubes;
    minCubes.push_back(0);
    minCubes.push_back(0);
    minCubes.push_back(0);

    for (std::map<std::string, int> currentRound : listOfRounds)
    {
        if (currentRound.contains("red"))
        {
            if (minCubes[0] < currentRound["red"])
            {
                minCubes[0] = currentRound["red"];
            }
        }

        if (currentRound.contains("green"))
        {
            if (minCubes[1] < currentRound["green"])
            {
                minCubes[1] = currentRound["green"];
            }
        }

        if (currentRound.contains("blue"))
        {
            if (minCubes[2] < currentRound["blue"])
            {
                minCubes[2] = currentRound["blue"];
            }
        }
    }

    return minCubes;
}

int Game::powerOfGame() {
    std::vector<int> minCubes = this->minimumNumberOfCubes();

    return minCubes[0] * minCubes[1] * minCubes[2];
    
}