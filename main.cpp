#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "fifo.h"
using namespace std;

/*
Ethan Dykes
Page replacement algorithm. Takes a txt file name as input, figures out which algorithm it is referring to
parses data and implements the algorithm in a simulated fashion. 
*/

string input();
void runAlg(string pageData);
int numFrames(string pageData);

int main() {
    /* 
    main implements the most basic values being read
    input() runs the input function which reads the file and parses to readable input
    runAlg() runs the algorithm based on the input data
    */

    string pageData;
    
    pageData = input();
    runAlg(pageData);


    return 0; 
}


string input() {
    // asks for user input for file name, and returns a string of the data from file. 
    int size = 0;
    string filename;
    string line;
    ifstream inputFile;
    cout << "Enter the name of the data file: ";
    cin >> filename;
    char c;

    inputFile.open(filename);
    // error overflow for unknown file names
    while (!inputFile) {
        cout << "Can not open '" << filename << "'." << endl;
        cout << "Enter another name: " << endl;
        cin >> filename;
        inputFile.open(filename);
    }
    inputFile.close();

    return line;
}
void runAlg(string pageData) {
    /* 
    takes the data from the file, parses for the first character of line
     uses this char to determine which algorithm to run and runs it
     */
    char firstChar = pageData.at(0);
    string algType;
    int frames = numFrames(pageData);
    cout << "Num Frames: " << frames << endl;
    if (firstChar == 'F') {
        algType = "First In First Out";
        cout << algType << endl;
        fifo alg(pageData, frames);
        alg.implementFIFO();
        alg.printData();

    }
    else if (firstChar == 'O') {
        algType = "Optimal";
        cout << algType << endl;
        // opt opt(pageData, frames);
    }
    else if (firstChar == 'L') {
        algType = "Least Recently Used";
    }
    else {
        algType = "Unable to Determine Algorithm Type";
    }
}

int numFrames(string pageData) {
    // takes the input data and determines how many frames are being utilized for the algorithm. 
    int frames = 0; 
    char letter = pageData.at(1);
    frames = letter - '0';
    return frames;

}
