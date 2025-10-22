#include <vector>

class NumArray {
private:
    std::vector<int> prefix_sums;

public: 
    NumArray(std::vector<int>& nums) {
        prefix_sums.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sums[i + 1] = prefix_sums[i] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix_sums[right + 1] - prefix_sums[left];
    }
};