// User function template for C++
class Solution {
  public:

    string removeDups(string &s) {
         vector<bool> seen(256, false); // ASCII charset
    string result;

    for (char c : s) {
        if (!seen[c]) {
            result.push_back(c);
            seen[c] = true;
        }
    }
    return result;// Your code goes here
    }
};