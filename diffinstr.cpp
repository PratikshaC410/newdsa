class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int counts[26] = {0}; 
        for (char c : s) {
            counts[c - 'a']++;
        }
        for (char c : t) {
            int index = c - 'a';
            
            counts[index]--;
            if (counts[index] < 0) {
                return c;
            }
        }
        return ' '; 
    }
};