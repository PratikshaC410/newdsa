class Solution {
public:
    bool balanced(long long x) {
        string s = to_string(x);
        vector<int> cnt(10, 0);
        for (char c : s) cnt[c - '0']++;

        // If '0' appears at all, it's invalid
        if (cnt[0] > 0) return false;

        // For every digit d that appears, it must appear exactly d times
        for (int d = 1; d <= 9; ++d) {
            if (cnt[d] != 0 && cnt[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        // Balanced numbers are small; this brute-force bound is safe and fast.
        for (long long x = (long long)n + 1; x <= 10000000; ++x) {
            if (balanced(x)) return (int)x;
        }
        return -1; // unreachable for problem constraints
    }
};
