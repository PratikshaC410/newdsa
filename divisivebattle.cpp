#include <bits/stdc++.h>
using namespace std;

int countPrimeFactors(int x)
{
    int cnt = 0;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            cnt++;
            x /= i;
        }
    }
    if (x > 1)
        cnt++;
    return cnt;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Check if already sorted
        bool sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            cout << "Bob\n";
            continue;
        }

        long long totalMoves = 0;

        for (int i = 0; i < n; i++)
        {
            int pf = countPrimeFactors(a[i]);
            totalMoves += (pf - 1);
        }

        if (totalMoves % 2 == 1)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}