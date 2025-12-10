class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> dp0(2, 0), dp1(2, 0);

        for (int x : nums) {
            int p = x & 1; // parity

            auto prev0 = dp0;
            auto prev1 = dp1;

            dp0[p] = max(dp0[p], prev0[p] + 1);
            dp0[p] = max(dp0[p], 1); // start new sequence

            dp1[p] = max(dp1[p], prev1[p ^ 1] + 1);
            dp1[p] = max(dp1[p], 1); // start new sequence
        }

        return max({dp0[0], dp0[1], dp1[0], dp1[1]});
    }
};