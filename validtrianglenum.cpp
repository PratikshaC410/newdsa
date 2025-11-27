class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;

    // Fix the largest side at position k
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                // All pairs (i, i+1, ..., j-1, j) with k form valid triangles
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }

    return count;
    }
};