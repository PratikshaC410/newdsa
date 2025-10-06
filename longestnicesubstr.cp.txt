
class Solution {
public:
    string longestNiceSubstring(string s) {
        return helper(s);
    }

private:
    string helper(string s) {
        if (s.size() < 2) return "";

        unordered_set<char> chars(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (chars.count(tolower(c)) && chars.count(toupper(c))) {
                continue; // good character
            }
            // split around bad character
            string left = helper(s.substr(0, i));
            string right = helper(s.substr(i + 1));

            if (left.size() >= right.size())
                return left;
            else
                return right;
        }
        // if we never split, the whole string is nice
        return s;
    }
};