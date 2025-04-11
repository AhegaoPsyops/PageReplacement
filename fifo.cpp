#include "fifo.h"
using namespace std;
/* 
Honestly, once FIFO is implemented, I might be able to just 
turn this class into an algorithms class and then make seperate functions
for each algorithm, either that or make an inherited superclass
*/

fifo::fifo(string pageData, int framesNo) {
	// Constructor using the given data, implements as private
	data = pageData;
	frames = framesNo;
	len = data.length() - 2; // Number of actual pages being processed
}

void fifo::implementFIFO() {
	// this is where the algorithm goes
	len = data.length() - 2;
	// I hate this already
	// initialize all 2d array values to -1
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 20; j++) {
			pages[i][j] = -1;
		}
	}


	
}

void fifo::printData() {
	// insert printed data, prebuild to format the needed data
	// test insert to see if data values would work
	string spacing = "   ";
	int testArray[20];
	// bullshittery with spacing
	for (int i = 0; i < 20; i++) {
		testArray[i] = rand()%10;
	}

	cout << "reference string" << endl;
	for (int i = 0; i < 20; i++) {
		cout << testArray[i] << spacing;
	}
	cout << endl << "page frames" << endl;
	//std::cout << std::setw(60) << "123456789123456789" << std::endl;
}
