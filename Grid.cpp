#include "Grid.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Grid::Grid() {
    initializeGrid();
}

void Grid::displayGrid() const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::moveVehicle(int x, int y) {
    // If we reached the goal
    if (grid[x][y] == 'F') {
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Define possible moves (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            if (moveVehicle(newX, newY)) {
                grid[newX][newY] = '*';  // Mark path
                return true;
            }
        }
    }
    return false; // If none of the moves lead to the goal, backtrack
}

void Grid::initializeGrid() {
    srand(time(nullptr));  // Seed the random number generator with the current time

    int vRow = 0;
    int vCol = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == vRow && j == vCol) {
                grid[i][j] = 'v';
            } else {
                int randVal = rand() % 10 + 1;
                bool nearVehicle = (i >= vRow - 1 && i <= vRow + 1) && (j >= vCol - 1 && j <= vCol + 1);

                grid[i][j] = (randVal <= 2 && !nearVehicle) ? 'o' : ' ';
            }
        }
    }

    grid[ROWS - 1][COLS - 1] = 'F'; // Set 'F' at bottom-right
}

bool Grid::isObstacleNextTo(int x, int y) const {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] == 'o') {
            return true;
        }
    }
    return false;
}

void Grid::findPosition(int &x, int &y) const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'v') {
                x = i;
                y = j;
                return;
            }
        }
    }
}

bool Grid::isValid(int x, int y) const {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != 'o' && !visited[x][y]);
}

void Grid::moveVehicleUserInput() {
    int x, y;
    findPosition(x, y);

    std::cout << "Enter direction (U = up, D = down, L = left, R = right): ";
    char dir;
    std::cin >> dir;

    int newX = x;
    int newY = y;

    switch(dir) {
        case 'U': newX = x - 1; break;
        case 'D': newX = x + 1; break;
        case 'L': newY = y - 1; break;
        case 'R': newY = y + 1; break;
        default: std::cout << "Invalid direction." << std::endl; return;
    }

    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] != 'o') {
        grid[x][y] = ' ';
        grid[newX][newY] = 'v';
        if (isObstacleNextTo(newX, newY)) {
            std::cout << "Warning: There's an obstacle next to you!" << std::endl;
        }
    } else {
        std::cout << "Cannot move in that direction." << std::endl;
    }
}
