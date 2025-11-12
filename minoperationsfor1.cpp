class Solution {
private:
    // Helper function for GCD (Euclidean algorithm)
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        int ones_count = 0;
        int overall_gcd = nums[0];

        // 1. Initial Checks and Edge Cases
        for (int x : nums) {
            if (x == 1) {
                ones_count++;
            }
            overall_gcd = gcd(overall_gcd, x);
        }

        // Case 1: Overall GCD > 1 (Impossible)
        if (overall_gcd > 1) {
            return -1;
        }

        // Case 2: Array already contains 1s
        if (ones_count > 0) {
            // Minimum operations is the number of non-1 elements
            return n - ones_count;
        }

        // 3. General Case: No 1s, but overall GCD is 1
        
        // Find the minimum length L_min of a subarray whose GCD is 1.
        int min_len = n + 1;

        for (int i = 0; i < n; ++i) {
            int current_gcd = nums[i];
            for (int j = i; j < n; ++j) {
                current_gcd = gcd(current_gcd, nums[j]);
                
                if (current_gcd == 1) {
                    int len = j - i + 1;
                    min_len = std::min(min_len, len);
                    // Found the shortest subarray starting at i, move to the next i
                    break; 
                }
            }
        }

        // Total operations = (min_len - 1) + (n - 1)
        return min_len + n - 2;
    }
};