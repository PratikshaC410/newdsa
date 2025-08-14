#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break; // No possible zero-sum if smallest > 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

            int l = i + 1, r = n - 1;
            while (l < r) {
                long sum = (long)nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l; // Skip dup left
                    while (l < r && nums[r] == nums[r - 1]) --r; // Skip dup right
                    ++l; --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    --r;
                }
            }
        }
        return res;
    }
};
