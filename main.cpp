#include "Grid.h"

#include <iostream>

int main() {
    Grid grid;
    grid.displayGrid();

    if (grid.moveVehicle(0, 0)) {
        std::cout << "Path found:\n";
        grid.displayGrid();
    } else {
        std::cout << "No path found to reach 'F'.\n";
    }

    return 0;
}
