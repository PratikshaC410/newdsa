#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;  // Base case: 0 odd numbers before starting
        int odds = 0, result = 0;

        for (int num : nums) {
            odds += num % 2;  // Increase if odd
            if (count.find(odds - k) != count.end()) {
                result += count[odds - k];
            }
            count[odds]++;
        }

        return result;
    }
};
