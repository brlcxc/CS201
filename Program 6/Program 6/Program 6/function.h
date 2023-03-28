#pragma once
#include <string>

using namespace std;

#ifndef FUNCTION_H
#define FUNCTION_H

bool CandyGame(int candyNum, int movesLeft = 20);
//The intitial number of candy is input and the moves left is set as 20
//If a solution is found the value true is returned and the steps are output. Otherwise false is returned 

bool PlayAgain();
//Nothing is input
//True or false is returned based off whether the user enters y or n

int GetCandyNum();
//Nothing is input
//The number of candy entered by the user is returned

#endif