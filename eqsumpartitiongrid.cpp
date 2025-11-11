class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
      
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();
        if (n == 0) return false;

        // 1. Calculate Total Sum T and Target Sum
        // Use long long for the sum to prevent potential overflow, as grid elements are positive integers.
        long long totalSum = 0;
        for (const auto& row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

        // Check Feasibility: Total sum must be even.
        if (totalSum % 2 != 0) {
            return false;
        }

        long long targetSum = totalSum / 2;

        // --- 2. Check for Horizontal Cut (Row-wise Sums) ---
        // A cut is placed after row i-1. The top section sum must equal targetSum.
        // We check cut positions i from 1 to m-1.
        long long currentHorizontalSum = 0;
        // The loop iterates over rows i = 0 up to m-2 (since we need m-1 cuts).
        for (int i = 0; i < m - 1; ++i) {
            // Calculate the sum of the current row (row i)
            long long rowSum = 0;
            for (int val : grid[i]) {
                rowSum += val;
            }
            currentHorizontalSum += rowSum;
            
            // If the sum of rows 0 to i equals the target sum, a valid horizontal cut exists.
            if (currentHorizontalSum == targetSum) {
                // [Image of a matrix grid with a horizontal line drawn between two rows,
                // and the two resulting sections are labeled with the same sum T/2]
                return true;
            }
            
            // Optimization: If the current sum exceeds the target, no deeper horizontal cut can work.
            if (currentHorizontalSum > targetSum) {
                break; 
            }
        }
        
        // --- 3. Check for Vertical Cut (Column-wise Sums) ---
        // A cut is placed after column j-1. The left section sum must equal targetSum.
        // We check cut positions j from 1 to n-1.
        long long currentVerticalSum = 0;
        
        // The loop iterates over columns j = 0 up to n-2 (since we need n-1 cuts).
        for (int j = 0; j < n - 1; ++j) {
            // Calculate the sum of the current column (column j)
            long long colSum = 0;
            for (int i = 0; i < m; ++i) {
                colSum += grid[i][j];
            }
            currentVerticalSum += colSum;

            // If the sum of columns 0 to j equals the target sum, a valid vertical cut exists.
            if (currentVerticalSum == targetSum) {
                // [Image of a matrix grid with a vertical line drawn between two columns,
                // and the two resulting sections are labeled with the same sum T/2]
                return true;
            }

            // Optimization: If the current sum exceeds the target, no further vertical cut can work.
            if (currentVerticalSum > targetSum) {
                break;
            }
        }

        // 4. Conclusion
        return false;
    }
};  
    
