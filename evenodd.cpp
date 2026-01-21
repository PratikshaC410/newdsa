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
        int n;
        cin >> n;

        int even = 0, odd = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        if (even == n && odd == n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
