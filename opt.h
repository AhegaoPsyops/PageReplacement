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
	int framesNo;
public:
	opt(std::string pageData, int framesNo);
	void parseData(std::string pageData, int* data);
	void optimal();
	void printOutput();
};
