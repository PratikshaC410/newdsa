class Solution {
public:
    bool reorderedPowerOf2(int n) {
            string s = to_string(n);
        sort(s.begin(), s.end());

        // Check all powers of 2 up to 2^30 (which fits in int)
        for (int i = 0; i < 31; i++) {
            int p = (1 << i);
            string t = to_string(p);
            sort(t.begin(), t.end());
            if (s == t) return true;
        }

        return false;
    }
};