#pragma once

#include "Media.h"
#include <string>
using namespace std;

#ifndef AUDIO_h
#define AUDIO_H

class Audio:public Media {
public:
	Audio();
	Audio(string identifier, string name, int runTime, string format, string quality);
	virtual string getType() const;
	virtual void ReadData(istream& is);
	virtual void WriteData(ostream& os);
private:
	string format;
	string quality;
};

#endif