#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1)
        {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << "\n";
        }
        else
        {
            // x == 1
            if (k == 1)
            {
                cout << "NO\n";
            }
            else
            {
                // use 2 if n is even
                if (n % 2 == 0)
                {
                    cout << "YES\n";
                    cout << n / 2 << "\n";
                    for (int i = 0; i < n / 2; i++)
                        cout << 2 << " ";
                    cout << "\n";
                }
                else
                {
                    // n odd then need a 3
                    if (k >= 3)
                    {
                        cout << "YES\n";
                        cout << 1 + (n - 3) / 2 << "\n";
                        cout << 3 << " ";
                        for (int i = 0; i < (n - 3) / 2; i++)
                            cout << 2 << " ";
                        cout << "\n";
                    }
                    else
                    {
                        cout << "NO\n";
                    }
                }
            }
        }
    }

    return 0;
}
