#include "fifo.h"
using namespace std;
/*
Ethan Dykes
First In First Out Algorithm
Constructor initializes data, sets array values to -1, and cuts the first two letters out of our string
implementFIFO() implements the algorithm, placing it in the 2d array pages[][]
printData() prints the data to console in the required placement. 
*/

fifo::fifo(string pageData, int framesNo) {
	// Constructor using the given data, implements as private
	data = pageData;
	frames = framesNo;
	// since our metadata has been processed already, we can remove the first two letters of the string
	string newData;
	for (int i = 2; i < data.length(); i++) {
		newData += data.at(i);
	}
	data = newData;
	// initializes our array to -1 values, indicates empty
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 20; j++) {
			pages[i][j] = -1;
		}
	}
	len = data.length(); // number of actual pages being processed
}

void fifo::implementFIFO() {
	// implements the algorithm and sets values in the 2D array. 
	// current page values in frames
	int frameContent[9];
	// index for the oldest page to be replaced
	int oldestIndex = 0;
	// step in the reference string
	//int currentStep = 0;

	// initialize all frame contents to -1 so code knows its empty
	for (int i = 0; i < frames; i++) {
		frameContent[i] = -1;
	}

	for (int currentStep = 0; currentStep < len && currentStep < 20; currentStep++) {
		int currentPage = data[currentStep] - '0';

		// conditional that evaluates if the page has been placed for this frame
		bool found = false;
		for (int i = 0; i < frames; i++) {
			if (frameContent[i] == currentPage) {
				found = true;
				break;
			}
		}

		// if not found, replace the oldest page
		if (!found) {
			frameContent[oldestIndex] = currentPage;
			oldestIndex = (oldestIndex + 1) % frames; 
		}

		// record frameContent into the 2D pages array
		for (int i = 0; i < frames; i++) {
			pages[i][currentStep] = frameContent[i];
		}

		//currentStep++;
	}
}
	


void fifo::printData() {
	// printing data to required output
	// basic initializer for width, allows for more dynamic spacing for output testing
	int w = 5;
	cout << "reference string" << endl;
	for (int i = 0; i < len && i < 20; i++) {
		cout << setw(w) << data.at(i);
	}
	cout << endl;

	// Print page frame state row by row
	// finding setw made my life much easier
	for (int row = 0; row < frames; row++) {
		for (int col = 0; col < len && col < 20; col++) {
			if (pages[row][col] == -1) {
				cout << setw(w) << " ";  
			}
			else {
				cout << setw(w) << pages[row][col];
			}
		}
		cout << endl;
	}

	cout << endl << "page frames" << endl;
}