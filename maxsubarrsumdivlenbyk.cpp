class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
    long long pref = 0;
    long long ans = LLONG_MIN;

    // For each remainder r = i % k, store minimum prefix sum and its index
    vector<pair<long long,int>> best(k, {LLONG_MAX, -1});

    // prefix index 0 has remainder 0
    best[0] = {0, 0};

    for (int i = 1; i <= n; i++) {
        pref += nums[i-1];
        int r = i % k;

        // check earlier prefix with same index remainder
        if (best[r].second != -1) {
            ans = max(ans, pref - best[r].first);
        }

        // update best
        if (pref < best[r].first) {
            best[r] = {pref, i};
        }
    }

    return ans;
}
};