#include <string>
#include <iostream>
#include "Video.h"
using namespace std;

Video::Video() : Media() {
	resolution = "None";
	format = "None";
	quality = "None";
}

Video::Video(string identifier, string name, int runTime, string format, string quality, string resolution) : Media(identifier, name, runTime) {
	this->resolution = resolution;
	this->format = format;
	this->quality = quality;
}

string Video::getType() const {
	return "Video";
}

void Video::ReadData(istream& is) {
	Media::ReadData(is);
	is >> resolution >> format;
	is.ignore();
	getline(is, quality);
}

void Video::WriteData(ostream& os) {
	Media::WriteData(os);
	os << resolution << endl;
	os << format << endl;
	os << quality << endl;
}