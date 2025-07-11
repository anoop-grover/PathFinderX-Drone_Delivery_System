#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10; // Grid size
vector<vector<int>> grid(N, vector<int>(N, 0)); // 0=open, 1=obstacle, 2=path

pair<int, int> source, destination;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to print grid with markings
void printGrid() {
    cout << "\n🗺️ City Grid Layout:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (make_pair(i, j) == source)
                cout << "S ";
            else if (make_pair(i, j) == destination)
                cout << "D ";
            else if (grid[i][j] == 1)
                cout << "X ";
            else if (grid[i][j] == 2)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Check if a cell is valid to move
bool isValid(int x, int y, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            grid[x][y] == 0 && !visited[x][y]);
}

// BFS pathfinding logic
bool bfsPath() {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
    queue<pair<int, int>> q;

    q.push(source);
    visited[source.first][source.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == destination) {
            vector<pair<int, int>> path;
            pair<int, int> curr = destination;

            while (curr != source) {
                path.push_back(curr);
                curr = parent[curr.first][curr.second];
            }
            path.push_back(source);
            reverse(path.begin(), path.end());

            // Mark the path on the grid
            for (int i = 1; i < path.size() - 1; i++) {
                int r = path[i].first;
                int c = path[i].second;
                grid[r][c] = 2;
            }

            // Print the path steps
            cout << "\n✅ Shortest Path Found (BFS):\n";
            for (auto cell : path) {
                cout << "(" << cell.first << "," << cell.second << ") ";
            }
            cout << "\n📏 Total Steps: " << path.size() - 1 << endl;

            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << "\n❌ No valid path from Source to Destination.\n";
    return false;
}

int main() {
    int obs;
    cout << "🚁 Welcome to PathFinderX – Drone Delivery System 🚁\n";
    cout << "Grid Size: " << N << "x" << N << endl;

    // Get obstacle input
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

    // Source & destination input
    cout << "Enter source coordinates (row col): ";
    cin >> source.first >> source.second;

    cout << "Enter destination coordinates (row col): ";
    cin >> destination.first >> destination.second;

    printGrid();
    bfsPath();
    printGrid(); // Show grid with path

    return 0;
}
