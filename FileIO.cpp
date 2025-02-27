/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream stream;
	stream.open(filename.c_str(), ios::in);
	if (!stream.is_open()) {
		stream.close();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	std:string line;
	while (getline(stream, line)) {
		contents += line;
	}
	stream.close();

	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputstream;
	outputstream.open(filename.c_str());
	if (!outputstream.is_open()) {
		outputstream.close();
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	for (int i = 0 ; i < myEntryVector.size() ; i++) {
		outputstream << myEntryVector[i] << endl;
	}
	outputstream.close();
	return SUCCESS;
}


