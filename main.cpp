#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 5;
const int COLS = 5;
const int RAND_MAX_VAL = 10;  // for random number generation

// Find the current position of the vehicle
void findPosition(const char grid[ROWS][COLS], int &x, int &y) {
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

// Check if there's an obstacle next to the given cell
bool isObstacleNextTo(const char grid[ROWS][COLS], int x, int y) {
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

// Function to move the vehicle based on user input
void moveVehicleUserInput(char grid[ROWS][COLS]) {
    int x, y;
    findPosition(grid, x, y);

    std::cout << "Enter direction (U = up, D = down, L = left, R = right): ";
    char dir;
    std::cin >> dir;

    int newX = x;
    int newY = y;

    switch(dir) {
        case 'W': newX = x - 1; break;
        case 'S': newX = x + 1; break;
        case 'A': newY = y - 1; break;
        case 'D': newY = y + 1; break;
        default: std::cout << "Invalid direction." << std::endl; return;
    }

    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY] != 'o') {
        grid[x][y] = ' ';
        grid[newX][newY] = 'v';
        if (isObstacleNextTo(grid, newX, newY)) {
            std::cout << "Warning: There's an obstacle next to you!" << std::endl;
        }
    } else {
        std::cout << "Cannot move in that direction." << std::endl;
    }
}

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