#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int rows = 5; 
    const int cols = 5;

    char randomArray[rows][cols]; 

    // Seed the random number generator with current time
    srand(time(NULL));

    // Randomly choose a position for 'v'
    int vRow = rand() % rows;
    int vCol = rand() % cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == vRow && j == vCol) {
                randomArray[i][j] = 'v';
            } else {
                int randVal = rand() % 10 + 1;

                // Ensure no obstacles around 'v'
                bool nearVehicle = (i >= vRow - 1 && i <= vRow + 1) && (j >= vCol - 1 && j <= vCol + 1);
                
                if (randVal <= 2 && !nearVehicle) {
                    randomArray[i][j] = 'o';
                } else {
                    randomArray[i][j] = ' ';
                }
            }
        }
    }

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << randomArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
