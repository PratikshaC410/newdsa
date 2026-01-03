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

        int sum = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if (x % 2 == 1)
                odd++;
        }

        if (sum % 2 == 0 && odd != 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
