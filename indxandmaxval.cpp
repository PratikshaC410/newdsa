#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        long long mx = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        while (m--)
        {
            char c;
            long long l, r;
            cin >> c >> l >> r;

            if (l <= mx && mx <= r)
            {
                if (c == '+')
                    mx++;
                else
                    mx--;
            }

            cout << mx << " ";
        }

        cout << "\n";
    }

    return 0;
}