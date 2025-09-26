#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long operations = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                int needed = nums[i] + 1;  // strictly greater than nums[i]
                operations += (needed - nums[i + 1]);
                nums[i + 1] = needed;  // update next element
            }
        }
        return operations;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};  // example input

    cout << "Minimum operations: " << sol.minOperations(nums) << endl;
    return 0;
}
