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
        long long a, b, n;
        cin >> a >> b >> n;

        long long k = a / b;

        if (n <= k)
            cout << n << "\n";
        else
            cout << k + 1 << "\n";
    }

    return 0;
}