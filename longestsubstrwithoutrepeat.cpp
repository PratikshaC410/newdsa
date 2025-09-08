#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex; // stores last index of each char
    int maxLen = 0;
    int start = 0; // left pointer of window

    for (int end = 0; end < s.size(); end++) {
        char c = s[end];

        // If character seen before and inside current window
        if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= start) {
            start = lastIndex[c] + 1; // move left pointer
        }

        lastIndex[c] = end; // update last index
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
