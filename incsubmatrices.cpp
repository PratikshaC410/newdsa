#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Calculates the final matrix after performing all submatrix updates using the 2D Difference Array technique.
     * * Time Complexity: O(Q + n^2), where Q is the number of queries.
     * Space Complexity: O(n^2) for the difference and result matrices.
     */
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // 1. Initialize the n x n difference matrix.
        // It serves as the intermediate step to accumulate all updates.
        vector<vector<int>> diff_mat(n, vector<int>(n, 0));

        // 2. Process all queries by applying the four marks on the difference matrix.
        for (const auto& query : queries) {
            int r1 = query[0];
            int c1 = query[1];
            int r2 = query[2];
            int c2 = query[3];
            int v = 1; // The value to add for each query

            // Operation 1: Add v at (r1, c1)
            diff_mat[r1][c1] += v;

            // Operation 2: Subtract v at (r2 + 1, c1) - boundary check is crucial
            if (r2 + 1 < n) {
                diff_mat[r2 + 1][c1] -= v;
            }

            // Operation 3: Subtract v at (r1, c2 + 1) - boundary check
            if (c2 + 1 < n) {
                diff_mat[r1][c2 + 1] -= v;
            }

            // Operation 4: Add v at (r2 + 1, c2 + 1) - boundary check
            if (r2 + 1 < n && c2 + 1 < n) {
                diff_mat[r2 + 1][c2 + 1] += v;
            }
        }

        // 3. Compute the result matrix (mat) by calculating the 2D prefix sum of diff_mat.
        vector<vector<int>> mat(n, vector<int>(n));
        
        // Loop over rows
        for (int r = 0; r < n; ++r) {
            // Loop over columns
            for (int c = 0; c < n; ++c) {
                // Initialize mat[r][c] with the value from the difference matrix
                mat[r][c] = diff_mat[r][c];
                
                // Add the value from the cell directly above (r-1, c)
                if (r > 0) {
                    mat[r][c] += mat[r - 1][c];
                }
                
                // Add the value from the cell directly to the left (r, c-1)
                if (c > 0) {
                    mat[r][c] += mat[r][c - 1];
                }
                
                // Subtract the value from the top-left diagonal cell (r-1, c-1) 
                // to correct for the double-counting in the previous two additions
                if (r > 0 && c > 0) {
                    mat[r][c] -= mat[r - 1][c - 1];
                }
            }
        }

        return mat;
    }
};