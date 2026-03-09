#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> r(n);
        for (int i = 0; i < n; i++)
            cin >> r[i];

        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        vector<int> all;
        for (int x : r)
            all.push_back(x);
        for (int x : b)
            all.push_back(x);
        sort(all.begin(), all.end(), greater<int>());

        int f = 0;
        int prefSum = 0;
        for (int x : all)
        {
            prefSum += x;
            f = max(f, prefSum);
        }

        cout << f << "\n";
    }

    return 0;
}