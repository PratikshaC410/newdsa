#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long a;
        cin >> n >> a;

        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long L = 0, R = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i] < a)
                L++;
            else if (v[i] > a)
                R++;
        }

        if (L > R)
            cout << 0 << "\n";
        else
            cout << 2000000000 << "\n";
    }

    return 0;
}