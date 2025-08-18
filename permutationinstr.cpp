class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        int need[26] = {0}, win[26] = {0};
        for (char c : s1) need[c - 'a']++;

        // build first window
        for (int i = 0; i < n; ++i) win[s2[i] - 'a']++;

        auto same = [&](){
            for (int i = 0; i < 26; ++i)
                if (need[i] != win[i]) return false;
            return true;
        };
        if (same()) return true;

        // slide the window
        for (int r = n; r < m; ++r) {
            win[s2[r] - 'a']++;                // include right char
            win[s2[r - n] - 'a']--;            // exclude left char
            if (same()) return true;
        }
        return false;
    }
};
