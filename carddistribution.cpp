#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long sum = a + b + c;
        if (sum % 3 != 0)
        {
            cout << "NO\n";
            continue;
        }
        long long T = sum / 3;
        if (T >= b && T <= c - 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}