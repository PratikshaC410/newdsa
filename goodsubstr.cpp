
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if (n < 3) return 0;

        int count = 0;
        unordered_map<char, int> freq;
        for (int i = 0; i < 3; i++) {
            freq[s[i]]++;
        }
        if (freq.size() == 3) count++;
        for (int i = 3; i < n; i++) {
            char left = s[i - 3];
            if (--freq[left] == 0) {
                freq.erase(left);
            }
            freq[s[i]]++;
            if (freq.size() == 3) {
                count++;
            }
        }
        return count;
    }
};