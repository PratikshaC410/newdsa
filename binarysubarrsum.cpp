#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        int current_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            current_sum += num;
            if (prefix_counts.count(current_sum - goal)) {
                total_subarrays += prefix_counts[current_sum - goal];
            }
            prefix_counts[current_sum]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    int result1 = solution.numSubarraysWithSum(nums1, goal1);
    cout << "Number of subarrays with sum " << goal1 << ": " << result1 << endl;

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    int result2 = solution.numSubarraysWithSum(nums2, goal2);
    cout << "Number of subarrays with sum " << goal2 << ": " << result2 << endl;

    return 0;
}