#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<long long> a;
        int l = 0, r = n - 1;

        while (l <= r)
        {
            if (l == r)
            {
                a.push_back(b[l]);
            }
            else
            {
                a.push_back(b[l]);
                a.push_back(b[r]);
            }
            l++;
            r--;
        }

        for (long long x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
