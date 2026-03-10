#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int hikes = 0;
        int i = 0;

        while (i <= n - k)
        {
            bool valid = true;
            int j;
            for (j = i; j < i + k; j++)
            {
                if (a[j] == 1)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                hikes++;
                i += k + 1;
            }
            else
            {
                i = j + 1;
            }
        }

        cout << hikes << "\n";
    }

    return 0;
}