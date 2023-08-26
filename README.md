# ADAS-Simulation-with-Object-Detection-and-Collision-Avoidance-cpp-DFS

DFS is an algorithm for traversing or searching tree or graph data structures. One starts at the root and explores as far as possible along each branch before backtracking.

The main idea behind DFS is to go deeper into the graph whenever possible.
Implementation:

    Base Case: If the current cell is the goal, stop and return true.
    Visit Current Cell: Mark the current cell as visited.
    Explore Neighbors: Look at the cells around the current one (up, down, left, and right). For each neighboring cell:
        Check if it's a valid cell to visit (it should be within the grid, not an obstacle, and not already visited).
        If valid, move to that cell and call the DFS function recursively.
        If, from that cell, we find a path to the goal, return true.
    Backtrack: If none of the neighboring cells lead to a solution, return false. This backtracks to the previous cell.

Code Breakdown:

Here's the related code from your project and a step-by-step explanation:
1. Helper Function isValid:

cpp

bool isValid(const char grid[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != 'o' && !visited[x][y]);
}

This function checks whether a given cell (x, y) is valid to move to. The cell is valid if:

    It's inside the grid boundaries (x >= 0 && x < ROWS && y >= 0 && y < COLS).
    It's not an obstacle (grid[x][y] != 'o').
    It hasn't been visited yet (!visited[x][y]).

2. Recursive DFS Function moveVehicle:

cpp

bool moveVehicle(char grid[ROWS][COLS], bool visited[ROWS][COLS], int x, int y) {
    if (grid[x][y] == 'F') {
        return true;
    }

    visited[x][y] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(grid, visited, newX, newY)) {
            if (moveVehicle(grid, visited, newX, newY)) {
                grid[newX][newY] = 'v';
                return true;
            }
        }
    }

    return false;
}

    If the current cell contains 'F', we've reached our destination. So, we return true.
    Mark the current cell as visited: visited[x][y] = true.
    The arrays dx and dy help in moving up, down, left, and right, respectively.
    We loop through the possible neighbors of the current cell using the for-loop.
        Calculate the coordinates of the neighboring cell: newX = x + dx[i] and newY = y + dy[i].
        If this neighboring cell is valid, we recursively call moveVehicle for it.
        If we found a path from that cell (the recursive call returns true), we mark it as part of our path grid[newX][newY] = 'v' and return true.
    If none of the neighbors lead to a solution, we return false.

3. Main Call:

In the main() function, the moveVehicle function is called initially for the starting position of 'v', which is (0, 0) in your setup.

cpp

if (moveVehicle(grid, visited, 0, 0)) {
    std::cout << "Path found:\n";
    displayGrid(grid);
} else {
    std::cout << "No path found to reach 'F'.\n";
}

This will attempt to find a path from the starting cell (0, 0) to the goal 'F'. If a path is found, it's displayed; otherwise, a "No path found" message appears.

DFS explores as far as possible along each branch before backtracking. In this 2D grid scenario, it means the algorithm will try to move as far as possible in one direction before being blocked and then trying another direction.
