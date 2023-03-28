#include <string>
#include <iostream>
#include "function.h"
using namespace std;

bool CandyGame(int candyNum, int movesLeft) {
	int newCandyNum;
	bool solutionFound = false;

	//base case that returns false when no solution is found
	if (movesLeft == 0) {
		return false;
	}
	//base case that prints and returns true only if 17 is found
	else if (candyNum == 17) {
		cout << "Found solution. I have exactly 17 Candies, with " << movesLeft << " moves left." << endl;
		return true;
	}
	else {
		//using if rather than if else allows other possible branches to be checked if the first returns false
		if (candyNum % 2 == 0) {
			newCandyNum = candyNum / 2;
			solutionFound = CandyGame(newCandyNum, movesLeft - 1);
			if (solutionFound) {
				cout << "Reduce " << candyNum << " by half to get " << newCandyNum << "." << endl;
			}
		}
		if (candyNum % 3 == 0 && !solutionFound) {
			newCandyNum = candyNum + candyNum / 3;
			solutionFound = CandyGame(newCandyNum, movesLeft - 1);
			if (solutionFound) {
				cout << "With " << candyNum << ", add 1/3 to get " << newCandyNum << "." << endl;
			}	
		}
		if (!solutionFound) {
			newCandyNum = candyNum + 23;
			solutionFound = CandyGame(newCandyNum, movesLeft - 1);
			if (solutionFound) {
				cout << "With " << candyNum << ", add 23 to get " << newCandyNum << "." << endl;
			}
		}

	}
}

bool PlayAgain() {
	char userChoice;

	while (true) {
		cout << endl << "Would you like to try again [Y/N]? ";
		cin >> userChoice;
		//allows both upper and lower case
		if (toupper(userChoice) == 'Y')
			return true;
		else if (toupper(userChoice) == 'N')
			return false;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

}

int GetCandyNum() {
	int candyInput;
	while (true) {
		cout << "How many Candies are you starting with? ";
		cin >> candyInput;
		//Checks that the input is within the range
		if (candyInput <= 1000 && candyInput > 0)
			return candyInput;
		else
			cout << "Number of Candies must be greater than 0 and no more than 1000" << endl;
	}
}