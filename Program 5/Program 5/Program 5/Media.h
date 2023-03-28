#pragma once

#include <string>
using namespace std;

#ifndef MEDIA_H
#define MEDIA_H

class Media {
public:
	Media();
	Media(string identifier, string name, int runTime);
	//returns the identifier
	string getIdentifier();
	//returns the name
	string getName();
	//returns the run time
	int getRunTime();
	//sets identifier
	void setIdentifier(string identifier);
	//sets name
	void setName(string name);
	//sets run time
	void setRunTime(int runTime);
	//returns type of media used
	virtual string getType() const = 0;
	//Reads data from a file stream which is input as the parameter
	virtual void ReadData(istream& is);
	//Writes data from an output file stream which is input as the parameter
	virtual void WriteData(ostream& os);
private:
	string identifier;
	string name;
	int runTime;
};

#endif