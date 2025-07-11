#include <iostream>
#include <vector>
using namespace std;

const int N = 10; // Grid size (10x10)
vector<vector<int>> grid(N, vector<int>(N, 0)); // 0=open, 1=obstacle

pair<int, int> source, destination;

// Function to print the grid with S, D, and obstacles
void printGrid() {
    cout << "\nCity Grid Layout:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (make_pair(i, j) == source)
                cout << "S "; // Source
            else if (make_pair(i, j) == destination)
                cout << "D "; // Destination
            else if (grid[i][j] == 1)
                cout << "X "; // Obstacle
            else
                cout << ". "; // Open space
        }
        cout << endl;
    }
}

int main() {
    int obs;
    cout << "🚁 Welcome to PathFinderX – Drone Delivery System 🚁\n";
    cout << "Grid Size: " << N << "x" << N << endl;

    // Obstacle Input
    cout << "\nEnter number of obstacles: ";
    cin >> obs;

    cout << "Enter obstacle positions (row col):\n";
    for (int i = 0; i < obs; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= 0 && x < N && y >= 0 && y < N)
            grid[x][y] = 1;
        else
            cout << "⚠️ Invalid coordinates! Ignored.\n";
    }

    // Source Input
    cout << "Enter source coordinates (row col): ";
    cin >> source.first >> source.second;

    // Destination Input
    cout << "Enter destination coordinates (row col): ";
    cin >> destination.first >> destination.second;

    // Print Final Grid
    printGrid();

    return 0;
}
