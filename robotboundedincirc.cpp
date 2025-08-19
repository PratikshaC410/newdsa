#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRobotBounded(string instructions) {
    // Directions: north, east, south, west
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0;  // initial position
    int dir = 0;       // 0 = north

    for (char ch : instructions) {
        if (ch == 'G') {
            x += directions[dir].first;
            y += directions[dir].second;
        } else if (ch == 'L') {
            dir = (dir + 3) % 4; // turn left
        } else if (ch == 'R') {
            dir = (dir + 1) % 4; // turn right
        }
    }

    // If after one cycle:
    // - robot is back to (0, 0) OR
    // - robot is not facing north
    // Then it's bounded
    return (x == 0 && y == 0) || (dir != 0);
}
