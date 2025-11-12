class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
         int count = 0;
    for (int i = 0; i < words.size(); i++) {
        string w = words[i];
        // Check if w is a prefix of s
        if (s.size() >= w.size() && s.substr(0, w.size()) == w) {
            count++;
        }
    }
    return count;
    }
};