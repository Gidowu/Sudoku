// No work has been done beyond the source code given in the book
// Please include the standard info about yourself and the program here

#include <iostream>
#include <cmath>
#include <fstream>
#include "sudoku.h"

using namespace std;

int main() {
    sudoku puzzle;
    int initialGrid[9][9];
    string inputFileName, outputFileName;

    // Get input and output file names from the user
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    // Read the puzzle from the input file
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            inputFile >> initialGrid[i][j];
    inputFile.close();

    puzzle.initializeSudokuGrid(initialGrid);

    cout << "Initial Sudoku Grid:" << endl;
    puzzle.printSudokuGrid();

    // Solve the puzzle
    if (puzzle.solveSudoku()) {
        cout << "Sudoku Solution:" << endl;
        puzzle.printSudokuGrid();

        // Write the solution to the output file
        ofstream outputFile(outputFileName);
        if (outputFile) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    outputFile << puzzle.getGridValue(i, j) << " ";
                }
                outputFile << endl;
            }
            outputFile.close();
            cout << "Solution written to " << outputFileName << endl;
        } else {
            cerr << "Error: Cannot open output file." << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
