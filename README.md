# Vehicle Navigation Grid

A simple grid-based navigation simulator implemented in C++. The grid contains a vehicle represented by the character 'v' which aims to reach the finish line represented by the character 'F'. The grid can also have obstacles represented by the character 'o'.

## Table of Contents

- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)
- [Contributions](#contributions)

## Features

1. **Dynamic Grid Creation**: A 5x5 grid is randomly generated with the start (vehicle) at the top-left and the finish line at the bottom-right. Obstacles are randomly placed within the grid but not too close to the starting position.

2. **User Interaction**: Users can manually navigate the vehicle using keyboard directions.

3. **DFS-based Path Finder**: The simulator uses a Depth First Search (DFS) approach to find a path from the vehicle's starting position to the finish line.

4. **Obstacle Warning**: The simulator provides warnings if the vehicle is next to an obstacle.

## Setup

1. Ensure you have a C++ compiler installed on your system.
2. Clone or download the repository.
3. Compile the code using your preferred C++ compiler.

## Usage

1. Run the compiled executable.
2. The initial grid will be displayed.
3. The simulator will automatically find a path from the vehicle's position to the finish line using DFS.
4. If a path is found, it'll be displayed with `*` marking the path.

## Contributions

Contributions to improve the simulator are welcome. Please fork the repository and submit a pull request.

