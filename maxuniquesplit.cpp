#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;

    void backtrack(string &s, int start, unordered_set<string> &used)
    {
        if (start == s.size())
        {
            ans = max(ans, (int)used.size());
            return;
        }

        string curr = "";
        for (int i = start; i < s.size(); i++)
        {
            curr += s[i];

            if (used.find(curr) == used.end())
            {
                used.insert(curr);
                backtrack(s, i + 1, used);
                used.erase(curr); // backtrack
            }
        }
    }

    int maxUniqueSplit(string s)
    {
        unordered_set<string> used;
        backtrack(s, 0, used);
        return ans;
    }
};