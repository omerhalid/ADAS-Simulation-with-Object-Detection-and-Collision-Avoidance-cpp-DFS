#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 5;
const int COLS = 5;
const int RAND_MAX_VAL = 10;  // for random number generation

// Function to initialize the grid
void initializeGrid(char grid[ROWS][COLS]) {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Randomly choose a position for 'v'
    //it is not random at the moment, come back to here later
    int vRow = 0;
    int vCol = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == vRow && j == vCol) {
                grid[i][j] = 'v';
            } else {
                int randVal = rand() % RAND_MAX_VAL + 1;
                bool nearVehicle = (i >= vRow - 1 && i <= vRow + 1) && (j >= vCol - 1 && j <= vCol + 1);

                if (randVal <= 2 && !nearVehicle) {
                    grid[i][j] = 'o';
                } else {
                    grid[i][j] = ' ';
                }
            }
        }
    }

    // Set 'F' at bottom-right
    grid[ROWS-1][COLS-1] = 'F';
}

// Function to display the grid
void displayGrid(const char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    char grid[ROWS][COLS];
    initializeGrid(grid);
    displayGrid(grid);

    return 0;
}
