class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
         int cnt = k;  

    for (int num : nums) {
        if (num == 1) {
            if (cnt < k) {
                return false;
            }
            cnt = 0; 
        } else {
            cnt++; 
        }
    }
    return true;
    }
};