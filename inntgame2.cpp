#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long diff = llabs(a - b);
        int moves = 0;

        while (diff > 0)
        {
            if (diff >= 10)
            {
                diff -= 10;
            }
            else
            {
                diff = 0;
            }
            moves++;
        }

        cout << moves << '\n';
    }
    return 0;
}
