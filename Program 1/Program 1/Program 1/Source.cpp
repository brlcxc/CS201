// Bishop Lohman
// Program 1
// CS201R-2
// Created 2/3/21
// Due 2/6/21

#include <iostream>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	const double FOURPACK = 13.2, SIXPACK = 19.49, PARTYBOX = 34.08;
	double total = 0;
	char playAgain = 'y';

	cout << "Welcome to KC Cookies" << endl;
	cout << "We offer 3 different packs of Cookies" << endl;
	cout << "4 Pack Box        $" << FOURPACK << endl;
	cout << "6 Pack Box        $" << SIXPACK << endl;
	cout << "Party Box'12'     $" << PARTYBOX << endl;

	while (playAgain != 'n') {
	int userInput;
	int userAmount;

	cout << endl << "What would you like to order today" << endl;
	cout << "1 ==> 4-Pack Cookies" << endl;
	cout << "2 ==> 6-Pack Cookies" << endl;
	cout << "3 ==> Party Box(12-Pack Cookies)" << endl;
	cout << "Please enter '1 or 2 or 3' to proceed:" << endl;

	cin >> userInput;

	cout << endl << "How many packs do you want?" << endl;

	cin >> userAmount;

	switch (userInput) {
	case 1:
		cout << endl << "You ordered: " << userAmount << " 4-Pack Cookies";
		total += userAmount * FOURPACK;
		break;
	case 2:
		cout << endl << "You ordered: " << userAmount << " 6-Pack Cookies";
		total += userAmount * SIXPACK;
		break;
	case 3:
		cout << endl << "You ordered: " << userAmount << " Party Pack Cookies";
		total += userAmount * PARTYBOX;
		break;
	default:
		cout << endl << "error" << endl;
		break;
	}
	do {
		cout << endl << "Do you want to add anything else?Y/y or N/n" << endl;
		cin >> playAgain;
		playAgain = tolower(playAgain);
	} while (((playAgain != 'n') && (playAgain != 'y')));

	if (playAgain == 'n') {
		break;
	}

	}
	cout << "Total of your order is $ " << total << endl;

}