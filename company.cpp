#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int divisors = 0;

    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors++;
            if (i != n / i)
                divisors++;
        }
    }

    cout << divisors - 1 << '\n';

    return 0;
}
