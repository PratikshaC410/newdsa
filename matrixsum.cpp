int n = grid.size(), m = grid[0].size();
    vector<int> dp(k + 1, -1e9);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> row = grid[i];
        sort(row.rbegin(), row.rend());  // sort descending

        // prefix sums up to limits[i]
        vector<int> prefix = {0};
        for (int j = 0; j < min((int)row.size(), limits[i]); ++j)
            prefix.push_back(prefix.back() + row[j]);

        vector<int> new_dp = dp;
        for (int taken = 0; taken <= k; ++taken) {
            if (dp[taken] < 0) continue;
            for (int x = 1; x < (int)prefix.size(); ++x) {
                if (taken + x <= k) {
                    new_dp[taken + x] = max(new_dp[taken + x], dp[taken] + prefix[x]);
                }
            }
        }
        dp = move(new_dp);
    }

    return *max_element(dp.begin(), dp.end());
}