#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int &x : b)
            cin >> x;

        int ans = 0;

        for (int s = 0; s < n; s++)
        {
            int last = -1;
            int cnt = 0;

            for (int k = 0; k < 2 * n; k++)
            {
                int i = (s + k) % n;
                if (b[i] > last)
                {
                    last = b[i];
                    cnt++;
                }
            }

            ans = max(ans, cnt);
        }

        cout << ans << "\n";
    }
}