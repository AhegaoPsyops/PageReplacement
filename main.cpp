#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

string input() {
    int size = 0;
    string filename;
    string line;
    ifstream inputFile;
    cout << "Enter the name of the data file: ";
    cin >> filename;
    char c;

    inputFile.open(filename);

    while (!inputFile) {
        cout << "I'm sorry, I could not open '" << filename << "'." << std::endl;
        cout << "Please enter another name: " << std::endl;
        cin >> filename;
        inputFile.open(filename);
    }
    getline(inputFile, line); 
    /*while (getline(inputFile, line)) {
        cout << line << endl;
    }*/

    while (inputFile.get(c)) {
        size++;
    }

    // cout << "File size is " << size << " characters" << std::endl;


    inputFile.close();

    return line; 

}
string type(string pageData) {
    char firstChar = pageData.at(0);
    string algType;
    if (firstChar == 'F') {
        algType = "First In First Out";
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
    return algType;
}

int main() {
    string pageData;
    string algType;
    pageData = input();
    cout << pageData << endl;
    algType = type(pageData);
    cout << "Algorithm Type is " << algType;

    return 0; 
}