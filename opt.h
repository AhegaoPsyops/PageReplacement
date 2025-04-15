#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class opt
{
private:
	std::string data;
	int framesNo = 0;
public:
	opt(std::string pageData);
	void parseData(std::string pageData, int size, int* data);
	void printbreak(int size);
	int findlength(int frame[], int n, int* data, int location, int size);
	bool checkdupe(int frame[], int* data, int i);
};
