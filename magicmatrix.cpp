class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Check numbers 1-9 and distinct
        bool used[10] = {false};
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9) return false;
                if (used[val]) return false; 
                used[val] = true;
            }
        }

        // Center must be 5
        if (grid[r+1][c+1] != 5) return false;

        // Sum of rows, cols, diagonals must be 15
        int s1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int s2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
        int s3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];

        if (s1 != 15 || s2 != 15 || s3 != 15) return false;

        int c1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        int c2 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
        int c3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];

        if (c1 != 15 || c2 != 15 || c3 != 15) return false;

        int d1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int d2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        if (d1 != 15 || d2 != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < rows - 2; r++) {
            for (int c = 0; c < cols - 2; c++) {
                if (isMagic(grid, r, c)) count++;
            }
        }

        return count;
    }
};
