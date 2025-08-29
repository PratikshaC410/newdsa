#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // already valid

        int k = 2; // pointer for placement, first two elements are always allowed

        for (int i = 2; i < n; i++) {
            // Only keep nums[i] if it's not the same as nums[k-2]
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
