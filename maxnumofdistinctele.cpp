class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long nextFree = LLONG_MIN;
        unordered_set<long long> used;
        
        for (long long num : nums) {
            long long low = num - k;
            long long high = num + k;

            // Move nextFree to within the valid range
            nextFree = max(nextFree, low);

            // If we exceeded range, skip
            if (nextFree > high) 
                continue;

            used.insert(nextFree);
            nextFree++; // Next distinct value
        }

        return used.size();
    }
};
