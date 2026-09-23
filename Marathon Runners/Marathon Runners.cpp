#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int runnerCount = 5;
const string dataFile = "runners.txt";

void readRunnerData(string filename, string names[runnerCount], int dailyMiles[runnerCount][7]);
void calculateTotalsAndAverages(int dailyMiles[runnerCount][7], int averages[runnerCount], int totals[runnerCount]);


int main()
{
    string runnerNames[runnerCount];
    int milesRun[runnerCount][7];
    int averageMiles[runnerCount];
    int totalMiles[runnerCount];

    readRunnerData(dataFile, runnerNames, milesRun);
    calculateTotalsAndAverages(milesRun, averageMiles, totalMiles);
    
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



void calculateTotalsAndAverages(int dailyMiles[runnerCount][7], int averages[runnerCount], int totals[runnerCount]) {
    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;
        int total = 0;

        while (dayCounter < 7) {
            total = total + dailyMiles[i][dayCounter];

            ++dayCounter;
        }
        
        totals[i] = total;
        averages[i] = total / 7;
    }
}