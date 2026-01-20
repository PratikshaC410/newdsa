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
        int n, x;
        cin >> n >> x;

        if (n <= 2)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 1 + (n - 2 + x - 1) / x << "\n";
        }
    }

    return 0;
}
