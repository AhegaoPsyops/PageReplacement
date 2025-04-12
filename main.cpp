#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "fifo.h"
using namespace std;

// Ethan Dykes
// Page replacement algorithm. Takes a txt file name as input, figures out which algorithm it is referring to
// parses data and implements the algorithm in a simulated fashion. 

// this is serious spaghetti code, classes in C++ make my brain hurt after not touching them for a year in place of java and python. 

// Lots of random commented cout lines, they exist for debugging. Remove before submission. 

string input();
void runAlg(string pageData);
int numFrames(string pageData);

int main() {
    // main, so far has a function that reads the data from the page and returns that type.
    // next returns the type of algorithm that it is
    // next feature will be a class that takes the algorithm, and then parses the txt file via delimiter and prints the data

    string pageData;
    string algType;
    int frames = 0;
    
    pageData = input();
    //frames = numFrames(pageData);
    runAlg(pageData);
    
   //cout << pageData << endl; 
   // cout << "Algorithm Type is " << algType;
    // cout << "Number of frames to be used is: " << frames; 


    return 0; 
}

// Function definitions here

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

    while (!inputFile) {
        cout << "Can not open '" << filename << "'." << endl;
        cout << "Enter another name: " << endl;
        cin >> filename;
        inputFile.open(filename);
    }
    //getline(inputFile, line);
    /*while (getline(inputFile, line)) {
        cout << line << endl;
    }*/
    // I hate this, it assumes that theres only pages 0-9
    // improve if opportunity
    while (inputFile.get(c)) {
        if (c != ',') {
            size++;
            line += c;
        }
    }

    // cout << "File size is " << size << " characters" << std::endl;


    inputFile.close();

    return line;

}
void runAlg(string pageData) {
    /* takes the data from the file, parses for the first character of line
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
    // will maybe implement this in algorithm classes. -\0-0/- its here for testing rn
    int frames = 0; 
    char letter = pageData.at(1);
    // cout << "Character selected: " << letter << endl;
    frames = letter - '0';
    return frames;

}
