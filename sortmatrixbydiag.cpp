class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    
    // Process diagonals starting from first column
    for (int row = 0; row < n; row++) {
        vector<int> diag;
        int r = row, c = 0;
        
        // Collect diagonal
        while (r < n && c < n) {
            diag.push_back(grid[r][c]);
            r++; c++;
        }
        
        // Sort descending (bottom-left triangle)
        sort(diag.begin(), diag.end(), greater<int>());
        
        // Place values back
        r = row; c = 0;
        for (int i = 0; i < diag.size(); i++) {
            grid[r][c] = diag[i];
            r++; c++;
        }
    }
    
    // Process diagonals starting from top row (skip main diagonal at col = 0)
    for (int col = 1; col < n; col++) {
        vector<int> diag;
        int r = 0, c = col;
        
        // Collect diagonal
        while (r < n && c < n) {
            diag.push_back(grid[r][c]);
            r++; c++;
        }
        
        // Sort ascending (top-right triangle)
        sort(diag.begin(), diag.end());
        
        // Place values back
        r = 0; c = col;
        for (int i = 0; i < diag.size(); i++) {
            grid[r][c] = diag[i];
            r++; c++;
        }
    }
    
    return grid; 
    }
};