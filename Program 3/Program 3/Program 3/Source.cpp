// Bishop Lohman
// Program 3
// CS201R-2
// Created 3/5/22
// Due 3/6/22

#include <iostream>
#include <fstream>
#include <string>
#include "checkingmodule.h"
using namespace std;

void main() {
	ifstream fin("input.txt");
	const int ARRAYSIZE = 10;
	int personNum = 0;
	string userID[ARRAYSIZE], userFirstName[ARRAYSIZE], userLastName[ARRAYSIZE];
	double userSaving[ARRAYSIZE], userChecking[ARRAYSIZE];
	char userInput = ' ';

	while (true) {
		for (int i = 0; i < 5; ++i) {
			if (fin.fail())
				break;
			switch (i) {
			case 0:
				fin >> userID[personNum];
				break;
			case 1:
				fin >> userFirstName[personNum];
				break;
			case 2:
				fin >> userLastName[personNum];
				break;
			case 3:
				fin >> userSaving[personNum];
				break;
			case 4:
				fin >> userChecking[personNum];
				break;
			}
		}
		if (fin.fail())
			break;
		personNum++;
	}

	while (tolower(userInput) != 'q') {
		PrintMenu();
		cin >> userInput;
		cout << endl;

		switch (tolower(userInput)) {
		case '1':
			PrintCustomersData(userID, userFirstName, userLastName, userSaving, userChecking, personNum);
			break;
		case '2':
			PrintNames(userFirstName, userLastName, personNum);
			break;
		case '3':
			PrintBankTotal(userID, userSaving, userChecking, personNum);
			break;
		case 'q':
			cout << "Thanks for using my program. Goodbye!!";
			break;
		default:
			cout << "Wrong input. try again..." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
	}
}