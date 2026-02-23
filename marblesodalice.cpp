#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long a;
    cin >> n >> a;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto it_low = lower_bound(v.begin(), v.end(), a);
    int count_less = distance(v.begin(), it_low);

    auto it_high = upper_bound(v.begin(), v.end(), a);
    int count_greater = distance(it_high, v.end());

    if (count_less >= count_greater)
    {
        cout << a - 1 << "\n";
    }
    else
    {
        cout << a + 1 << "\n";
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