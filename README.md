# ADAS-Simulation-with-Object-Detection-and-Collision-Avoidance-cpp-DFS

Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. This project implements DFS in a 2D grid simulation for an Automated Driver-Assistance System (ADAS) scenario, focusing on object detection and collision avoidance.
Project Overview

The main idea behind DFS in this context is to explore as deeply as possible into the grid, looking for a path to the goal, before backtracking if necessary. This project has been refactored to use Object-Oriented Programming (OOP) principles for better modularity and maintainability.
Implementation Details
Refactored Structure

    The codebase is divided into multiple files for clarity:
        Grid.h and Grid.cpp: These files contain the Grid class, which encapsulates all grid-related functionalities including initialization, displaying the grid, and moving within it using DFS.
        main.cpp: Contains the main function to run the simulation.

Core DFS Algorithm

    The DFS algorithm is implemented in the Grid class. It involves the following steps:
        Base Case: If the current cell is the goal ('F'), the search stops.
        Visit Current Cell: Mark the cell as visited.
        Explore Neighbors: Check adjacent cells (up, down, left, right) and recursively apply DFS on valid cells (not an obstacle and within grid boundaries).
        Backtrack: If no neighboring cells lead to a solution, backtrack to explore new paths.

Code Breakdown
Grid Class

    Grid::isValid(int x, int y) const: Checks if a cell is valid for traversal.
    Grid::moveVehicle(int x, int y): Recursive DFS function to find a path to the goal.

Main Logic

    The main() function in main.cpp initializes the grid and starts the DFS algorithm:

    ``` cpp

    Grid grid;
    if (grid.moveVehicle(0, 0)) {
        std::cout << "Path found:\n";
        grid.displayGrid();
    } else {
        std::cout << "No path found to reach 'F'.\n";
    }
    ```

How to Run

    Compile the project with a C++ compiler, ensuring to include both main.cpp and Grid.cpp.
    Run the compiled executable to start the simulation.

Contributions and Feedback

    Contributions to the project are welcome. Please ensure to follow best practices for code style and commenting.
    For feedback or issues, please open an issue in the repository.