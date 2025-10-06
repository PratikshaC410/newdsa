#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        
        int start = nums[0];
        
        for (int i = 1; i <= nums.size(); i++) {
            // If not consecutive OR end of array
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    // Single element range
                    result.push_back(to_string(start));
                } else {
                    // Range [start -> nums[i-1]]
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Move start to new position
                if (i < nums.size()) start = nums[i];
            }
        }
        return result;
    }
};
n#include <vector>
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
