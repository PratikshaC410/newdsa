class Solution {
public:
    bool isValid(const string& token) {
        bool hyphenUsed = false;
        bool punctuationUsed = false;
        int n = token.size();

        for (int i = 0; i < n; i++) {
            char c = token[i];

            if (isdigit(c)) {
                return false; // digits not allowed
            }

            if (c == '-') {
                // Only one hyphen allowed
                if (hyphenUsed) return false;
                hyphenUsed = true;

                // Must be surrounded by letters
                if (i == 0 || i == n-1) return false; // cannot be first or last
                if (!islower(token[i-1]) || !islower(token[i+1])) return false;

            } else if (c == '!' || c == '.' || c == ',') {
                // Only one punctuation allowed and must be last
                if (punctuationUsed) return false;
                punctuationUsed = true;

                if (i != n-1) return false; // must be at end
            } else {
                if (!islower(c)) return false; // only lowercase letters allowed
            }
        }

        return true;
    }

    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string token;
        int count = 0;

        while (ss >> token) {
            if (isValid(token)) count++;
        }

        return count;
    }
};
