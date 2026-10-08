#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int runnerCount = 5;
const string dataFile = "runners.txt";

struct Runner {
    string name;
    double miles[7];
    double average;
    double total;
};

void readRunnerData(string filename, Runner runners[runnerCount]);
void calculateTotalsAndAverages(Runner runners[runnerCount]);
void displayResults(Runner runners[runnerCount]);



int main()
{
    Runner runnersData[runnerCount];
    string runnerNames[runnerCount];
    double milesRun[runnerCount][7];
    double averageMiles[runnerCount];
    double totalMiles[runnerCount];

    readRunnerData(dataFile, runnersData);
    calculateTotalsAndAverages(runnersData);
    displayResults(runnersData);
}



void readRunnerData(string filename, Runner runners[runnerCount]) {
    ifstream inFile(filename);


    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return;
    }

    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;

        inFile >> runners[i].name;
        
        while (dayCounter < 7) {
            inFile >> runners[i].miles[dayCounter];

            ++dayCounter;
        }
    }
}



void calculateTotalsAndAverages(Runner runners[runnerCount]) {
    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;
        double total = 0;

        while (dayCounter < 7) {
            total = total + runners[i].miles[dayCounter];

            ++dayCounter;
        }
        
        runners[i].total = total;
        runners[i].average = total / 7;
    }
}

void displayResults(Runner runners[runnerCount]) {

    cout << setw(10) <<"Names" << setw(10) << "Sunday" << setw(10) << "Monday" << setw(10) << "Tuesday" << setw(10) << "Wednesday" << setw(10) << "Thursday" << setw(10) << "Friday" << setw(10) << "Saturday" << setw(14) << "Total Miles" << setw(20) << "Average Miles/Day" << endl;

    for (int i = 0; i < runnerCount; i++) {
        
        cout << setw(10) << runners[i].name;

        for (int day = 0; day < 7; day++) {
            cout << setw(10) << runners[i].miles[day];
        }

        cout << setw(14) << runners[i].total << setw(20) << runners[i].average << endl;
    }


}