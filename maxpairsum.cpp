#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

class Solution {
private:
    /**
     * @brief Finds the largest digit in an integer.
     * @param n The input integer.
     * @return The largest digit (1-9).
     */
    int findLargestDigit(int n) {
        int max_digit = 0;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            max_digit = std::max(max_digit, digit);
            temp /= 10;
        }
        return max_digit;
    }

public:
    int maxSum(std::vector<int>& nums) {
        // 1. Group numbers by their largest digit.
        // Key: Largest Digit (1 to 9)
        // Value: Vector of numbers sharing that largest digit
        std::unordered_map<int, std::vector<int>> digit_groups;

        for (int num : nums) {
            int largest_digit = findLargestDigit(num);
            digit_groups[largest_digit].push_back(num);
        }

        long long max_sum = -1;

        // 2. Iterate through groups and find the maximum pair sum.
        for (auto const& [digit, group] : digit_groups) {
            // A pair can only exist if the group has at least two numbers.
            if (group.size() < 2) {
                continue;
            }

            // Find the two largest numbers in the group.
            // Option A: Sort the group (O(N log N) per group)
            /*
            std::vector<int> sorted_group = group;
            std::sort(sorted_group.rbegin(), sorted_group.rend());
            long long current_sum = (long long)sorted_group[0] + sorted_group[1];
            */

            // Option B: Find the two largest elements in O(N) time for the group.
            int max1 = 0; // The largest number
            int max2 = 0; // The second largest number

            for (int num : group) {
                if (num > max1) {
                    max2 = max1; // Move old max1 to max2
                    max1 = num;  // Update max1
                } else if (num > max2) {
                    max2 = num;  // Update max2
                }
            }
            
            // max2 must be greater than 0 since group.size() >= 2 and all nums >= 1.
            long long current_sum = (long long)max1 + max2;
            
            max_sum = std::max(max_sum, current_sum);
        }

        // Return -1 if no such pair exists, otherwise return the max sum.
        // We cast the result to int as the return type requires.
        return (int)max_sum;
    }
};