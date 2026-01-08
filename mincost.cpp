#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, k;
    if (!(cin >> n >> k))
        return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    long long large_size = n - k + 1;
    long long total_cost = 0;

    for (int i = 0; i < large_size; i++)
    {
        total_cost += a[i] * large_size;
    }
    for (int i = large_size; i < n; i++)
    {
        total_cost += a[i] * 1;
    }

    cout << total_cost << endl;
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