#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdio>
#include <fstream>
using namespace std;
/*
Ethan Dykes
First In First Out Algorithm Header
Constructor initializes data, sets array values to - 1, and cuts the first two letters out of our string
implementFIFO() implements the algorithm, placing it in the 2d array pages[][]
printData() prints the data to console in the required placement.
*/

class fifo
{
private:
	// our data string
	string data;
	// num frames
	int frames;
	//length of string, important for our known read array length
	int len;
	// set max size to 9 frames and 20 pages
	int pages[9][20];

	int pagefaults;
public: 
	fifo(string pageData, int framesNo);
	void printData();
	void implementFIFO();
};

