#include <bits/stdc++.h>
using namespace std;

int main()
{

    int q;
    cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;

        int k = 0;
        while (k < s.size() && k < t.size() && s[k] == t[k])
        {
            k++;
        }

        int ans;
        if (k == 0)
        {
            ans = s.size() + t.size();
        }
        else
        {
            ans = s.size() + t.size() - k + 1;
        }

        cout << ans << "\n";
    }

    return 0;
}