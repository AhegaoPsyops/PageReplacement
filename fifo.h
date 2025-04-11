#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdio>
#include <fstream>
using namespace std;
class fifo
{
private:
	string data;
	int frames;
	int len;
	// set max size to 9 frames and 20 pages
	int pages[9][20];
public: 
	fifo(string pageData, int framesNo);
	void setData(string pageData);
	void setFrameNo(int framesNo);
	void printData();
	void implementFIFO();
};

