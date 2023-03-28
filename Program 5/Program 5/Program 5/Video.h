#pragma once

#include "Media.h"
#include <string>
using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video :public Media {
public:
	Video();
	Video(string identifier, string name, int runTime, string format, string quality, string resolution);
	virtual string getType() const;
	virtual void ReadData(istream& is);
	virtual void WriteData(ostream& os);
private:
	string resolution;
	string format;
	string quality;
};

#endif