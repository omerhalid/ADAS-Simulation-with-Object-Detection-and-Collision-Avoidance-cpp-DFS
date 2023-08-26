#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 5;
const int COLS = 5;
const int RAND_MAX_VAL = 10;  // for random number generation

// Create a helper function to check if a cell is within the grid and valid for the vehicle to move
bool isValid(const char grid[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != 'o' && !visited[x][y]);
}

// Recursive function for DFS algorithm
bool moveVehicle(char grid[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
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

        if (isValid(grid, visited, newX, newY)) {
            if (moveVehicle(grid, visited, newX, newY)) {
                grid[newX][newY] = '*';  // Mark path
                return true;
            }
        }
        
    }
    // If none of the moves lead to the goal, backtrack
    return false;
}

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
    bool visited[ROWS][COLS] = {false}; // Create a visited array to keep track of visited cells
    initializeGrid(grid);
    displayGrid(grid);

    if (moveVehicle(grid, visited, 0, 0)) {
        std::cout << "Path found:\n";
        grid[ROWS-1][COLS-1] = 'F';
        displayGrid(grid);
    } else {
        std::cout << "No path found to reach 'F'.\n";
    }

    return 0;
}