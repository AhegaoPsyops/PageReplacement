#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdio>
#include <fstream>

class opt
{
private:
	std::string data;
	const int framesNo = 3;
public:
	opt(std::string pageData);
	void parseData(std::string pageData, int size, int* data);
	void printbreak(int size);

};
