// Bishop Lohman
// Program 6
// CS201R-2
// Created 5/4/22
// Due 5/6/22

#include <iostream>
#include <string>
#include "function.h"

using namespace std;
void main() {
	int candyInput;

	while (true) {
		candyInput = GetCandyNum();

		cout << "Searching for a solution within 20 moves...." << endl;
		if (!CandyGame(candyInput)) {
			cout << "No solution found within 20 moves. Sorry." << endl;
		}

		if (!PlayAgain())
			break;
	}
}