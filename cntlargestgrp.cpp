class Solution {
private:
    // Helper function to calculate the sum of digits for a given number
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int countLargestGroup(int n) {
        // Step 1 & 2: Calculate digit sums and group counts
        // The map stores: {Digit Sum : Frequency/Group Size}
        map<int, int> group_sizes;
        
        for (int i = 1; i <= n; ++i) {
            int digit_sum = getDigitSum(i);
            group_sizes[digit_sum]++;
        }

        // Step 3: Find the maximum group size (maximum frequency)
        int max_size = 0;
        for (const auto& pair : group_sizes) {
            max_size = max(max_size, pair.second);
        }
        
    
        // Step 4: Count how many groups have this maximum size
        int count_max_groups = 0;
        for (const auto& pair : group_sizes) {
            if (pair.second == max_size) {
                count_max_groups++;
            }
        }
        
        return count_max_groups;
    }
}; 
    
