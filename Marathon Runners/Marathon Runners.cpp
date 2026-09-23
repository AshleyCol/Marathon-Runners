#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int runnerCount = 5;
const string dataFile = "runners.txt";

void readRunnerData(string filename, string names[runnerCount], double dailyMiles[runnerCount][7]);
void calculateTotalsAndAverages(double dailyMiles[runnerCount][7], double averages[runnerCount], double totals[runnerCount]);
void displayResults(string names[runnerCount], double dailyMiles[runnerCount][7], double averages[runnerCount], double totals[runnerCount]);


int main()
{
    string runnerNames[runnerCount];
    double milesRun[runnerCount][7];
    double averageMiles[runnerCount];
    double totalMiles[runnerCount];

    readRunnerData(dataFile, runnerNames, milesRun);
    calculateTotalsAndAverages(milesRun, averageMiles, totalMiles);
    displayResults(runnerNames, milesRun, averageMiles, totalMiles);
}



void readRunnerData(string filename, string names[runnerCount], double dailyMiles[runnerCount][7]) {
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



void calculateTotalsAndAverages(double dailyMiles[runnerCount][7], double averages[runnerCount], double totals[runnerCount]) {
    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;
        double total = 0;

        while (dayCounter < 7) {
            total = total + dailyMiles[i][dayCounter];

            ++dayCounter;
        }
        
        totals[i] = total;
        averages[i] = total / 7;
    }
}

void displayResults(string names[runnerCount], double dailyMiles[runnerCount][7], double averages[runnerCount], double totals[runnerCount]) {

    cout << setw(10) <<"Names" << setw(10) << "Sunday" << setw(10) << "Monday" << setw(10) << "Tuesday" << setw(10) << "Wednesday" << setw(10) << "Thursday" << setw(10) << "Friday" << setw(10) << "Saturday" << setw(14) << "Total Miles" << setw(20) << "Average Miles/Day" << endl;

    for (int i = 0; i < runnerCount; i++) {
        
        cout << setw(10) << names[i];

        for (int day = 0; day < 7; day++) {
            cout << setw(10) << dailyMiles[i][day];
        }

        cout << setw(14) << totals[i] << setw(20) << averages[i] << endl;
    }


}