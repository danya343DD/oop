#pragma once
class Point
{
public:
	double x;
	double y;
	double z;

	void enterCoordinates();
	void printCoordinates();
	void saveToFile();
	bool loadFromFile();
};

const char* const FILE_NAME = "coordinates.dat";

