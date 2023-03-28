// Bishop Lohman
// Program 2
// CS201R-2
// Created 2/21/22
// Due 2/22/22

#include <iostream>
#include <vector>
#include <cctype>
#include <ctime>  
using namespace std;

void OutputCards(vector<int> cards);
//The function will take an integer vector 
//The contents of the vector will be output

void TransferCards(vector<int>& liveCards, vector<int>& deadCards, int cardIndex, int cardValue);
//The function will take two integer vectors, the card index, and the card value
//The values will be removed from the live deck and added to the dead deck

void SortDeck(vector<int>& cards);
//The function will take a vector of type int
//The vector will be sorted by ascending order

bool GetAnswer();
//The function takes no parameters
//A boolean value is returned based off the user choice

void main() {
	vector<int> liveCards, deadCards;
	int currentScore, topCard, randomCard, randomCardIndex;
	bool answer;
	char playAgain;
	srand(time(0));

	cout << "Welcome to Take It or Leave It" << endl << endl;

	while (true) {
		currentScore = 0;
		topCard = 0;
		deadCards.clear();

		for (int i = 1; i <= 16; ++i) {
			liveCards.push_back(i);
		}

		while (true) {
			randomCardIndex = rand() % (liveCards.size());
			randomCard = liveCards.at(randomCardIndex);

			cout << "Current Score: " << currentScore << endl;
			cout << "Dead Cards:   ";
			OutputCards(deadCards);
			cout << endl << "Live Cards:   ";
			OutputCards(liveCards);
			cout << endl << "Next Cards: " << randomCard;
			if (randomCard > topCard) {
				answer = GetAnswer();
				cout << endl;
				if (answer == true) {
					currentScore += randomCard;
					if (randomCard > topCard)
						topCard = randomCard;
				}
			}
			else {
				cout << " Dead" << endl << endl;
			}

			TransferCards(liveCards, deadCards, randomCardIndex, randomCard);
			SortDeck(deadCards);

			if (liveCards.size() == 0)
				break;
		}

		do {
			cout << "Do you want to play again? (y/n)" << endl;
			cin >> playAgain;
		} while (!((tolower(playAgain)) == 'y' or (tolower(playAgain) == 'n')));

		if (tolower(playAgain) == 'n')
			break;
	}

}
void OutputCards(vector<int> cards) {
	for (unsigned int i = 0; i < cards.size(); ++i) {
		cout << cards.at(i) << "   ";
	}
}

void TransferCards(vector<int>& liveCards, vector<int>& deadCards, int cardIndex, int cardValue) {
	deadCards.push_back(cardValue);
	liveCards.erase(liveCards.begin() + cardIndex);
}

void SortDeck(vector<int>& cards) {
	int lowestCard, temp;
	for (unsigned int i = 0; i < cards.size() - 1; ++i) {
		lowestCard = i;
		for (unsigned int j = i + 1; j < cards.size(); ++j) {
			if (cards.at(j) < cards.at(i))
				lowestCard = j;
		}

		temp = cards.at(i);
		cards.at(i) = cards.at(lowestCard);
		cards.at(lowestCard) = temp;
	}
}

bool GetAnswer() {
	char userInput;

	cout << endl << "Take it [T] or leave it [L]? ";

	while (true) {
		cin >> userInput;
		if (tolower(userInput) == 't')
			return true;
		else if (tolower(userInput) == 'l')
			return false;
	}
}