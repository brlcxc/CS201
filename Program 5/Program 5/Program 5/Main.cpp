// Bishop Lohman
// Program 5
// CS201R-2
// Created 4/17/22
// Due 4/24/22

#include <iostream>
#include "Audio.h"
#include "Video.h"
#include "Media.h"
#include <iomanip>
#include <fstream>
using namespace std;

void main() {
	char mediaType;
	Media* mediaArray[200];
	Audio* audioItem = NULL;
	Video* videoItem = NULL;
	int count = 1;
	ifstream fin("Program5Data.txt");
	ofstream fout("audio.txt");
	ofstream fout2("video.txt");

	//Creates either audio or video class instances depending on the data type
	while (fin.good()) {
		fin >> mediaType;
		switch (mediaType) {
		case 'A':
			audioItem = new Audio;
			audioItem->ReadData(fin);
			mediaArray[count] = audioItem;
			break;
		case 'V':
			videoItem = new Video;
			videoItem->ReadData(fin);
			mediaArray[count] = videoItem;
			break;
		}
		count++;
	}

	//Sorts the instances based off the result of the getType() function 
	for (int i = 1; i < count - 1; ++i) {
		if (mediaArray[i]->getType() == "Audio") {
			mediaArray[i]->WriteData(fout);
			fout << setfill('*') << setw(35) << "" << endl;
		}
		else if (mediaArray[i]->getType() == "Video") {
			mediaArray[i]->WriteData(fout2);
			fout2 << setfill('*') << setw(35) << "" << endl;
		}
	}

	fin.close();
	fout.close();
	fout2.close();

}
