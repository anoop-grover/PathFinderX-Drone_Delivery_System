#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 10; // Grid size
vector<vector<int>> grid(N, vector<int>(N, 0)); // 0=open, 1=obstacle, 2=path

pair<int, int> source, destination;
vector<pair<int, int>> deliveries;
int batteryLimit = 30; // Default battery life
int totalStepsUsed = 0;

// Direction vectors: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Print the grid
void printGrid() {
    cout << "\n\U0001F5FA\uFE0F City Grid Layout:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pair<int, int> current = {i, j};
            if (current == source)
                cout << "S ";
            else if (current == destination)
                cout << "D ";
            else if (find(deliveries.begin(), deliveries.end(), current) != deliveries.end())
                cout << "P ";
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

// Check if a move is valid
bool isValid(int x, int y, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            grid[x][y] == 0 && !visited[x][y]);
}

// BFS function: returns steps and path between two points
int bfsPath(pair<int, int> start, pair<int, int> end, vector<pair<int, int>>& pathOut) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == end) {
            vector<pair<int, int>> path;
            pair<int, int> curr = end;

            while (curr != start) {
                path.push_back(curr);
                curr = parent[curr.first][curr.second];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());

            pathOut = path;
            return path.size() - 1; // total steps
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

    return -1; // no path
}

int main() {
    int obs;
    cout << "\U0001F681 Welcome to PathFinderX – Drone Delivery System \U0001F681\n";
    cout << "Grid Size: " << N << "x" << N << endl;

    // Input obstacles
    cout << "\nEnter number of obstacles: ";
    cin >> obs;

    cout << "Enter obstacle positions (row col):\n";
    for (int i = 0; i < obs; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= 0 && x < N && y >= 0 && y < N)
            grid[x][y] = 1;
        else
            cout << "\u26A0\uFE0F Invalid coordinates! Ignored.\n";
    }

    // Input source and destination
    cout << "Enter source coordinates (row col): ";
    cin >> source.first >> source.second;

    cout << "Enter destination coordinates (row col): ";
    cin >> destination.first >> destination.second;

    // Input delivery stops
    int deliveryCount;
    cout << "\nEnter number of delivery stops (0 if none): ";
    cin >> deliveryCount;

    for (int i = 0; i < deliveryCount; i++) {
        int x, y;
        cout << "Enter delivery stop " << i + 1 << " (row col): ";
        cin >> x >> y;
        deliveries.push_back({x, y});
    }

    // Battery input
    cout << "Enter drone battery limit (steps allowed): ";
    cin >> batteryLimit;

    printGrid();

    // Execute delivery path segment by segment
    vector<pair<int, int>> fullPath;
    pair<int, int> current = source;
    bool success = true;

    vector<pair<int, int>> allStops = deliveries;
    allStops.push_back(destination);

    for (auto stop : allStops) {
        vector<pair<int, int>> segmentPath;
        int steps = bfsPath(current, stop, segmentPath);

        if (steps == -1) {
            cout << "\n❌ No path from (" << current.first << "," << current.second
                 << ") to (" << stop.first << "," << stop.second << ")\n";
            success = false;
            break;
        }

        totalStepsUsed += steps;

        // Battery check
        if (totalStepsUsed > batteryLimit) {
            cout << "\n🔋 Battery limit exceeded! Mission failed.\n";
            success = false;
            break;
        }

        // Mark path (except source/dest)
        for (int i = 1; i < segmentPath.size() - 1; i++) {
            grid[segmentPath[i].first][segmentPath[i].second] = 2;
        }

        fullPath.insert(fullPath.end(), segmentPath.begin(), segmentPath.end() - 1);
        current = stop;
    }

    if (success) {
        fullPath.push_back(destination);
        cout << "\n✅ Final Drone Delivery Path:\n";
        for (auto p : fullPath)
            cout << "(" << p.first << "," << p.second << ") ";
        cout << "\n📏 Total Steps Used: " << totalStepsUsed << " / " << batteryLimit << endl;
    }

    printGrid();
    return 0;
}
