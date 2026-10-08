#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int maxRunners = 50;
const int numberOfDays = 7;
const string dataFile = "runners.txt";

struct Runner {
    string name;
    double miles[numberOfDays];
    double average;
    double total;
};

int readRunnerData(string filename, Runner runners[maxRunners]);
void calculateTotalsAndAverages(int runnerCount, Runner runners[maxRunners]);
void displayResults(int runnerCount, Runner runners[maxRunners]);



int main()
{
    Runner runnersData[maxRunners];
    int runnerCount;

    runnerCount = readRunnerData(dataFile, runnersData);
    calculateTotalsAndAverages(runnerCount, runnersData);
    displayResults(runnerCount, runnersData);
}



int readRunnerData(string filename, Runner runners[maxRunners]) {
    ifstream inFile(filename);
    int i = 0;


    if (!inFile) {
        cout << "Error occured while opening file for reading!" << endl;

        return 0;
    }

    while (inFile) {
        int dayCounter = 0;

        inFile >> runners[i].name;

        while (dayCounter < numberOfDays) {
            inFile >> runners[i].miles[dayCounter];

            ++dayCounter;
        }
        i++;
    }
    i += -1;
    return i;
}



void calculateTotalsAndAverages(int runnerCount,  Runner runners[maxRunners]) {
    for (int i = 0; i < runnerCount; i++) {
        int dayCounter = 0;
        double total = 0;

        while (dayCounter < numberOfDays) {
            total = total + runners[i].miles[dayCounter];

            ++dayCounter;
        }
        
        runners[i].total = total;
        runners[i].average = total / numberOfDays;
    }
}

void displayResults(int runnerCount, Runner runners[maxRunners]) {

    cout << setw(10) <<"Names" << setw(10) << "Sunday" << setw(10) << "Monday" << setw(10) << "Tuesday" << setw(10) << "Wednesday" << setw(10) << "Thursday" << setw(10) << "Friday" << setw(10) << "Saturday" << setw(14) << "Total Miles" << setw(20) << "Average Miles/Day" << endl;

    for (int i = 0; i < runnerCount; i++) {
        
        cout << setw(10) << runners[i].name;

        for (int day = 0; day < 7; day++) {
            cout << setw(10) << runners[i].miles[day];
        }

        cout << setw(14) << runners[i].total << setw(20) << runners[i].average << endl;
    }


}