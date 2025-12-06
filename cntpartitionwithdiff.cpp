class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), pref(n + 1, 0);
        // dp[i] = number of ways to partition first i elements (nums[0..i-1])
        dp[0] = 1;
        pref[0] = dp[0]; // pref[i] = sum_{t=0..i} dp[t]

        deque<int> maxdq, mindq;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // maintain deques for max and min over current window
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[right]) maxdq.pop_back();
            while (!mindq.empty() && nums[mindq.back()] >= nums[right]) mindq.pop_back();
            maxdq.push_back(right);
            mindq.push_back(right);

            // move left until the window [left..right] satisfies max-min <= k
            while (!maxdq.empty() && !mindq.empty() && nums[maxdq.front()] - nums[mindq.front()] > k) {
                if (!maxdq.empty() && maxdq.front() == left) maxdq.pop_front();
                if (!mindq.empty() && mindq.front() == left) mindq.pop_front();
                ++left;
            }

            // dp[right+1] = sum_{t=left..right} dp[t] = pref[right] - pref[left-1] (if left>0)
            long long ways = pref[right];
            if (left > 0) ways = (ways - pref[left - 1] + MOD) % MOD;
            else ways %= MOD;

            dp[right + 1] = ways;
            pref[right + 1] = (pref[right] + dp[right + 1]) % MOD;
        }

        return (int)dp[n];
    }
};