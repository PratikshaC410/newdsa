#include <bits/stdc++.h>
using namespace std;

long long countDivisible(long long n, long long divisor)
{
    return n / divisor;
}

long long countGood(long long n)
{
    if (n < 2)
        return 0;

    long long bad = 0;

    bad += countDivisible(n, 2);
    bad += countDivisible(n, 3);
    bad += countDivisible(n, 5);
    bad += countDivisible(n, 7);

    bad -= countDivisible(n, 2 * 3);
    bad -= countDivisible(n, 2 * 5);
    bad -= countDivisible(n, 2 * 7);
    bad -= countDivisible(n, 3 * 5);
    bad -= countDivisible(n, 3 * 7);
    bad -= countDivisible(n, 5 * 7);

    bad += countDivisible(n, 2 * 3 * 5);
    bad += countDivisible(n, 2 * 3 * 7);
    bad += countDivisible(n, 2 * 5 * 7);
    bad += countDivisible(n, 3 * 5 * 7);
    bad -= countDivisible(n, 2 * 3 * 5 * 7);

    long long good = n - bad;

    if (n >= 1)
        good--;

    return good;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;

        long long answer = countGood(r) - countGood(l - 1);
        cout << answer << "\n";
    }

    return 0;
}