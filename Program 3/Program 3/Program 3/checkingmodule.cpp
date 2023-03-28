#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PrintMenu() {
	cout << "1. Print all customers data" << endl;
	cout << "2. Print names and IDs" << endl;
	cout << "3. Print accounts total" << endl;
	cout << "4. Enter q/Q to quit" << endl << endl;
	cout << "Enter your choice, or 'q' to quit: ";
}

void PrintCustomersData(string userID[], string userFirstName[], string userLastName[], double userSaving[], double userChecking[], int personNum) {
	cout << left << setw(10) << "Last" << setw(10) << "First" << setw(15) << "ID" << setw(20) << "Savings Account" << setw(20) << "Checking Account" << endl;
	for (int i = 0; i < personNum; ++i) {
		cout << setw(10) << userLastName[i] << setw(10) << userFirstName[i] << setw(15) << userID[i] << setw(20) << userSaving[i] << setw(20) << userChecking[i] << endl;
	}
}

void PrintNames(string userFirstName[], string userLastName[], int personNum) {
	int lowestNameIndex;
	string temp, temp2;

	for (int i = 0; i < (personNum - 1); ++i) {
		lowestNameIndex = i;
		for (unsigned int j = i + 1; j < (personNum); ++j) {
			if (userFirstName[j] < userFirstName[lowestNameIndex])
				lowestNameIndex = j;
		}

		temp = userFirstName[i];
		userFirstName[i] = userFirstName[lowestNameIndex];
		userFirstName[lowestNameIndex] = temp;

		temp2 = userLastName[i];
		userLastName[i] = userLastName[lowestNameIndex];
		userLastName[lowestNameIndex] = temp2;
		
		if (i > 0) {
			if (userFirstName[i] == userFirstName[i - 1]) {
				if (userLastName[i] < userLastName[i - 1]) {
					temp2 = userLastName[i];
					userLastName[i] = userLastName[i-1];
					userLastName[i-1] = temp2;
				}
			}
		}
	}

	cout << left << setw(10) << "First" << setw(10) << "Last" << endl;
	for (int i = 0; i < personNum; ++i) {
		cout << setw(10) << userFirstName[i] << setw(10) << userLastName[i] << endl;
	}

	cout << endl << setfill('*') << setw(31) << "" << endl << setfill(' ');
	cout << left << "Total Number of Customers is " << personNum << endl;
	cout << setfill('*') << setw(31) << "" << endl << setfill(' ');
}

void PrintBankTotal(string userID[], double userSaving[], double userChecking[], int personNum) {
	double total, grandTotal = 0;
	cout << left << setw(10) << "ID" << setw(20) << "Savings Account" << setw(20) << "Checking Account" << setw(12) << "Total" << endl;
	for (int i = 0; i < personNum; ++i) {
		total = userSaving[i] + userChecking[i];
		grandTotal += total;
		cout << setw(10) <<  userID[i] << setw(20) << userSaving[i] << setw(20) << userChecking[i] << setw(12) << total << endl;
	}

	cout << endl << setfill('*') << setw(34) << "" << endl << setfill(' ');
	cout << left << "The Bank total amount is $" << grandTotal << endl;
	cout << setfill('*') << setw(34) << "" << endl << setfill(' ');
}