#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;

    for (int i = 1; i <= n - 1; i++)
    {

        if (i > a)
            break;
        if (n - i > b)
            continue;

        int x1 = a / i;
        int x2 = b / (n - i);

        int curr = min(x1, x2);
        ans = max(ans, curr);
    }

    cout << ans << "\n";
}
