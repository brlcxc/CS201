#include <string>
#include <iostream>
#include "Audio.h"
using namespace std;

Audio::Audio() : Media() {
	format = "None";
	quality = "None";
}

Audio::Audio(string identifier, string name, int runTime, string format, string quality) : Media(identifier, name, runTime) {
	this->format = format;
	this->quality = quality;
}

string Audio::getType() const {
	return "Audio";
}

void Audio::ReadData(istream& is) {
	Media::ReadData(is);
	is >> format;
	is.ignore();
	getline(is, quality);
}

void Audio::WriteData(ostream& os) {
	Media::WriteData(os);
	os << format << endl;
	os << quality << endl;
}