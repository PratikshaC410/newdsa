class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int count = 0, maxCount = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) count++;
        }
        maxCount = count;

        // Slide the window
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i - k])) count--;
            maxCount = max(maxCount, count);

            // Optimization: max possible = k, so break early
            if (maxCount == k) return k;
        }

        return maxCount;
    }
};
