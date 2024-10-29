#include "sudoku.h"
#include <iostream>

using namespace std;

// Default constructor
sudoku::sudoku() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            grid[i][j] = 0;
}

// Constructor that initializes grid with an input array
sudoku::sudoku(int g[][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            grid[i][j] = g[i][j];
}

// Initialize grid with user input (optional implementation)
void sudoku::initializeSudokuGrid() {
    cout << "Enter Sudoku grid (0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
}

// Initialize grid with an existing 2D array
void sudoku::initializeSudokuGrid(int g[][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            grid[i][j] = g[i][j];
}

// Print Sudoku grid
void sudoku::printSudokuGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Find the first empty slot in the grid
bool sudoku::findEmptyGridSlot(int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Check if a number can be placed at a given row and column
bool sudoku::canPlaceNum(int row, int col, int num) {
    return !numAlreadyInRow(row, num) &&
           !numAlreadyInCol(col, num) &&
           !numAlreadyInBox(row - row % 3, col - col % 3, num);
}

// Check if a number is already in a given row
bool sudoku::numAlreadyInRow(int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Check if a number is already in a given column
bool sudoku::numAlreadyInCol(int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Check if a number is in a specific 3x3 box
bool sudoku::numAlreadyInBox(int boxStartRow, int boxStartCol, int num) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + boxStartRow][j + boxStartCol] == num)
                return true;
    return false;
}

// Solve Sudoku using backtracking and recursion
bool sudoku::solveSudoku() {
    int row, col;

    if (!findEmptyGridSlot(row, col))
        return true; // No empty slots means puzzle is solved

    for (int num = 1; num <= 9; num++) {
        if (canPlaceNum(row, col, num)) {
            grid[row][col] = num; // Try this number

            if (solveSudoku()) // Recursive call
                return true;

            grid[row][col] = 0; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

// Getter function to access grid values
int sudoku::getGridValue(int row, int col) const {
    return grid[row][col];
}
