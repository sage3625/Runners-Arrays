// Runners Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

 /*
 Program Overview:
 This program reads data from a file named "runners.txt" containing the names of five runners 
 and the number of miles run by each runner each day of the week. It then calculates the total 
 miles run by each runner and the average miles run per day, and displays the results in a table format.
 */

// Function prototypes
void readData(string runners[], int milesRun[][NUM_DAYS]);
// Preconditions: The function takes an array to store runner names and a 2D array to store miles run by each runner each day.
// Postconditions: The arrays are populated with data read from the input file.

void calculateTotalAndAverage(const string runners[], const int milesRun[][NUM_DAYS]);
// Preconditions: The function takes an array of runner names and a 2D array of miles run by each runner each day.
// Postconditions: The total miles run by each runner and the average miles run per day are calculated and displayed.

void displayResults(const string runners[], const int milesRun[][NUM_DAYS]);
// Preconditions: The function takes an array of runner names and a 2D array of miles run by each runner each day.
// Postconditions: The results, including the total miles run by each runner and the average miles run per day, are displayed.

int main() {
    string runners[NUM_RUNNERS];
    int milesRun[NUM_RUNNERS][NUM_DAYS];

    readData(runners, milesRun);
    calculateTotalAndAverage(runners, milesRun);
    displayResults(runners, milesRun);

    return 0;
}

void readData(string runners[], int milesRun[][NUM_DAYS]) {
    ifstream inputFile("runners.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> milesRun[i][j];
        }
    }

    inputFile.close();
}

void calculateTotalAndAverage(const string runners[], const int milesRun[][NUM_DAYS]) {
    cout << "Results:" << endl;
    cout << setw(15) << left << "Runner";
    cout << setw(8) << "Day1" << setw(8) << "Day2" << setw(8) << "Day3" << setw(8) << "Day4" << setw(8) << "Day5" << setw(8) << "Day6" << setw(8) << "Day7";
    cout << setw(10) << "Total" << setw(10) << "Average" << endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles += milesRun[i][j];
        }
        double averageMiles = static_cast<double>(totalMiles) / NUM_DAYS;

        cout << setw(15) << left << runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(8) << milesRun[i][j];
        }
        cout << setw(10) << totalMiles << setw(10) << fixed << setprecision(2) << averageMiles << endl;
    }
}

void displayResults(const string runners[], const int milesRun[][NUM_DAYS]) {
    // Output results
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
