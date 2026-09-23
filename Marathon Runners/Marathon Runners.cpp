#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int runnerCount = 5;
const string dataFile = "runners.txt";

void readRunnerData(string filename, string names[runnerCount], int dailyMiles[runnerCount][7]);


int main()
{
    string runnerNames[runnerCount];
    int milesRun[runnerCount][7];

    readRunnerData(dataFile, runnerNames, milesRun);

    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;

        cout << runnerNames[i] << " ";

        while (dayCounter < 7) {
            cout << milesRun[i][dayCounter] << " ";

            ++dayCounter;
        }

        cout << endl;
    }
}

void readRunnerData(string filename, string names[runnerCount], int dailyMiles[runnerCount][7]) {
    ifstream inFile(filename);
    
    
    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return;
    }

    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;

        inFile >> names[i];

        while (dayCounter < 7) {
            inFile >> dailyMiles[i][dayCounter];

            ++dayCounter;
        }
    }
}