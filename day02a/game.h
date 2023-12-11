#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

class Game
{

private:

int gameNumber{};

std::vector<std::map<std::string, int>> listOfRounds;

std::string removeCommas(std::string);

public:

Game(std::string line);

int getGameNumber();

/// @brief This says if the game is possible given a max amount of cubes, R, G, B
/// @param red cubes
/// @param green cubes
/// @param blue cubes
/// @return true if the game was possible, false if not
bool isPossible(int, int, int);

};



#endif