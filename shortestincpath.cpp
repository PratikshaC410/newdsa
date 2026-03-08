#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        if (y == 1 || x == y || x == y + 1)
            cout << -1 << "\n";
        else if (x < y)
            cout << 2 << "\n";
        else
            cout << 3 << "\n";
    }
}