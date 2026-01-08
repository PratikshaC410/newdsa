#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;

        long long L = k - 1;
        long long R = n - k;

        long long ans = min(n, 1 + m + min(L, R));
        cout << ans << "\n";
    }
    return 0;
}
