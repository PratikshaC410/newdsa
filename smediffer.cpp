#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        char target = s[n - 1];
        int ops = 0;
        for (char c : s)
            if (c != target)
                ops++;

        cout << ops << "\n";
    }
    return 0;
}