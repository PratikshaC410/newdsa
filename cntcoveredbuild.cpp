class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> minX, maxX;  // row -> min/max x
    unordered_map<int, int> minY, maxY;  // col -> min/max y

    // Initialize maps
    for (auto& b : buildings) {
        int x = b[0], y = b[1];

        if (!minX.count(y)) minX[y] = x;
        else minX[y] = min(minX[y], x);

        if (!maxX.count(y)) maxX[y] = x;
        else maxX[y] = max(maxX[y], x);

        if (!minY.count(x)) minY[x] = y;
        else minY[x] = min(minY[x], y);

        if (!maxY.count(x)) maxY[x] = y;
        else maxY[x] = max(maxY[x], y);
    }

    int covered = 0;

    for (auto& b : buildings) {
        int x = b[0], y = b[1];

        bool left  = (minX[y] < x);
        bool right = (maxX[y] > x);
        bool below = (minY[x] < y);
        bool above = (maxY[x] > y);

        if (left && right && above && below)
            covered++;
    }

    return covered; 
    }
};