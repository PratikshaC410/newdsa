#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    long long largestSquareArea(const std::vector<std::vector<int>>& bottomLeft, 
                                      const std::vector<std::vector<int>>& topRight) {
        
        int n = bottomLeft.size();
        if (n < 2) {
            return 0;
        }

        long long maxSide = 0;

        for (int i = 0; i < n; ++i) {
            int a_i = bottomLeft[i][0];
            int b_i = bottomLeft[i][1];
            int c_i = topRight[i][0];
            int d_i = topRight[i][1];

            for (int j = i + 1; j < n; ++j) {
                int a_j = bottomLeft[j][0];
                int b_j = bottomLeft[j][1];
                int c_j = topRight[j][0];
                int d_j = topRight[j][1];

                // Calculate Intersection Coordinates
                int x1 = std::max(a_i, a_j); 
                int y1 = std::max(b_i, b_j); 
                int x2 = std::min(c_i, c_j); 
                int y2 = std::min(d_i, d_j); 

                // Check for Valid Overlap
                if (x1 < x2 && y1 < y2) {
                    int width = x2 - x1;
                    int height = y2 - y1;

                    // Max Square Side is min(width, height)
                    long long currentSide = std::min(width, height);
                    maxSide = std::max(maxSide, currentSide);
                }
            }
        }

        // Return the area (side * side)
        return maxSide * maxSide;
    }
};
