#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long x;
    long long ans = LLONG_MAX;

    for (int i = 0; i < N; ++i)
    {
        cin >> x;
        ans = min(ans, llabs(x));
    }

    cout << ans << '\n';
    return 0;
}
