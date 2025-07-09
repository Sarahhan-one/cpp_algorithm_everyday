#include <iostream>
#include <vector>
using namespace std;

vector<string> grid;

bool checkRows(int row, char num) {
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) return false;
    }
    return true;
}

bool checkCols(int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return false;
    }
    return true;
}

bool check3x3(int row, int col, char num) {
    int iStart, iEnd, jStart, jEnd;
    if (row < 3 && col < 3) { iStart = 0; iEnd = 3, jStart = 0, jEnd = 3; }
    else if (row >= 3 && row < 6 && col < 3) { iStart = 3; iEnd = 6, jStart = 0, jEnd = 3; }
    else if (row >= 6 && row < 9 && col < 3) { iStart = 6; iEnd = 9, jStart = 0, jEnd = 3; }
    else if (row < 3 && col >= 3 && col < 6) { iStart = 0; iEnd = 3, jStart = 3, jEnd = 6; }
    else if (row >= 3 && row < 6 && col >= 3 && col < 6) { iStart = 3; iEnd = 6, jStart = 3, jEnd = 6; }
    else if (row >= 6 && row < 9 && col >= 3 && col < 6) { iStart = 6; iEnd = 9, jStart = 3, jEnd = 6; }
    else if (row < 3 && col >= 6 && col < 9) { iStart = 0; iEnd = 3, jStart = 6, jEnd = 9; }
    else if (row >= 3 && row < 6 && col >= 6 && col < 9) { iStart = 3; iEnd = 6, jStart = 6, jEnd = 9; }
    else { iStart = 6; iEnd = 9, jStart = 6, jEnd = 9; }

    for (int i = iStart; i < iEnd; i++) {
        for (int j = jStart; j < jEnd; j++) {
            if (grid[i][j] == num) return false;
        }
    }
    return true;
}

void printGrid() {
    for (int i = 0; i < 9; i++) {
        cout << grid[i] << '\n';
    }
}

void sudoku(int i, int j) {
    if (i == 9) { //exit condition
        printGrid();
        exit(0);
    }

    if (j == 9) {
        sudoku(i+1, 0); 
        return;
    }

    if (grid[i][j] != '0') {
        sudoku(i, j+1);
        return;
    }

    for (int k = '1'; k <= '9'; k++) {
        if (checkRows(i, k) && checkCols(j, k) && check3x3(i, j, k)) {
            grid[i][j] = k;
            sudoku(i, j+1);
            grid[i][j] = '0';
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        string temp;
        cin >> temp; 
        grid.push_back(temp);
    }

    // printGrid();
    sudoku(0, 0);
} 