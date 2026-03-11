#include <iostream>
#include <string>
#include <climits>
using namespace std;

int solve(string s, char c1, char c2)
{
    int n = s.size();
    int deletions = 0;

    int i = n - 1;
    while (i >= 0 && s[i] != c2)
    {
        i--;
        deletions++;
    }
    if (i < 0)
        return INT_MAX;

    i--;
    while (i >= 0 && s[i] != c1)
    {
        i--;
        deletions++;
    }
    if (i < 0)
        return INT_MAX;

    return deletions;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int ans = INT_MAX;
        ans = min(ans, solve(s, '0', '0'));
        ans = min(ans, solve(s, '2', '5'));
        ans = min(ans, solve(s, '5', '0'));
        ans = min(ans, solve(s, '7', '5'));

        if (ans == INT_MAX)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}