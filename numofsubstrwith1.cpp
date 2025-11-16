class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long result = 0, curr = 0;

        for (char c : s) {
            if (c == '1') {
                curr++;  // extend current run of 1s
            } else {
                result = (result + curr * (curr + 1) / 2) % MOD;
                curr = 0;  // reset on '0'
            }
        }

        // Add the last run if it ends with '1'
        result = (result + curr * (curr + 1) / 2) % MOD;

        return (int)result;
    }
};
