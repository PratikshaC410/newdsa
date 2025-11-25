class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    bool doesAliceWin(string s) {
        int vowel_count = 0;
        for (char c : s) {
            if (isVowel(tolower(c))) {
                vowel_count++;
            }
        }
        
        return vowel_count >= 1;
    }
};