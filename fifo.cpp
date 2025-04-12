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
	/* for reference to data
	string data;
	int frames;
	int len;
	// set max size to 9 frames and 20 pages
	int pages[9][20]{ -1 };
	*/
	// this is where the algorithm goes
	// conditional that evaluates if the page has been placed for this frame
	bool placed = false;
	len = data.length();
	// I hate this already
	// driver loop for assigning pages to frames
	for (int i = 0; i < len; i++) {
		// first loop is per page being added
		for (int h = 0; h < frames; h++) {
			if (i != 0) {
				// I fear i have gotten the dimensions swapped
				pages[i][h] = pages[i - 1][h];
			}
		}
		for (int j = 0; j < frames; j++) {
			// this loop parses pages down by frame to find the fit. 
			if (pages[i][j] == -1 && placed == false) {
				pages[i][j] = data.at(i + 3);
				placed = true; 
			}
		}

		placed = false; 
	}

	
}

void fifo::printData() {
	// insert printed data, prebuild to format the needed data
	// test insert to see if data values would work
	string spacing = "   ";
	int testArray[20];
	// bullshittery with spacing
	len = data.length();

	cout << "reference string" << endl;
	for (int h = 2; h < len; h++) {
		cout << data.at(h) << spacing;
	}
	cout << endl; 
	for (int j = 0; j < frames; j++) {
		for (int i = 2; i < len + 2; i++) {
			cout << pages[j][i] << spacing;
		}
		cout << endl;
	}
	cout << endl << "page frames" << endl;
	//std::cout << std::setw(60) << "123456789123456789" << std::endl;
}
