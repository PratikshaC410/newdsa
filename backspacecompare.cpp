class Solution {
public:
    string buildString(const string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '#') {
                if (!st.empty()) st.pop(); // simulate backspace
            } else {
                st.push(c);
            }
        }
        
        // Build final string from stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);

   
    }
};