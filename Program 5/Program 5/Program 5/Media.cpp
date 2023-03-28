#include <string>
#include <iostream>
#include "Media.h"
using namespace std;

Media::Media() {
	identifier = "None";
	name = "None";
	runTime = 0;
}

Media::Media(string identifier, string name, int runTime) {
	this->identifier = identifier;
	this->name = name;
	this->runTime = runTime;
}

string Media::getIdentifier() {
	return identifier;
}

string Media::getName() {
	return name;
}

int Media::getRunTime() {
	return runTime;
}

void Media::setIdentifier(string identifier) {
	this->identifier = identifier;
}

void Media::setName(string name) {
	this->name = name;
}

void Media::setRunTime(int runTime) {
	this->runTime = runTime;
}

void Media::ReadData(istream& is) {
	is >> identifier;
	is.ignore();
	getline(is, name);
	is >> runTime;
}

void Media::WriteData(ostream& os) {
	os << identifier << endl;
	os << name << endl;
	os << runTime << endl;
}