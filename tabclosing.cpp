#include <iostream>

using namespace std;

void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;

    long long k = a / b;

    if (n <= k)
    {
        cout << n << "\n";
    }
    else
    {
        cout << k + 1 << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}