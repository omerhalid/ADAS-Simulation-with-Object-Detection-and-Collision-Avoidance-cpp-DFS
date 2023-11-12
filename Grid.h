#ifndef GRID_H
#define GRID_H

class Grid {
private:
    static const int ROWS = 5;
    static const int COLS = 5;
    char grid[ROWS][COLS];
    bool visited[ROWS][COLS] = {false};

public:
    Grid();
    void displayGrid() const;
    bool moveVehicle(int x, int y);
    void initializeGrid();
    bool isObstacleNextTo(int x, int y) const;
    void findPosition(int &x, int &y) const;
    bool isValid(int x, int y) const;
    void moveVehicleUserInput();
};

#endif // GRID_H
