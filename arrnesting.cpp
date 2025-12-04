#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            int currentLength = 0;
            int index = i;

            while (nums[index] != -1) {
                int next = nums[index];
                nums[index] = -1; // mark visited
                index = next;
                currentLength++;
            }
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
