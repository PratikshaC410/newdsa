#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<long long> L(n);
    for (int i = 0; i < n; i++)
        cin >> L[i];

    long long maxKill = 0;
    int alive = 0;

    long long minStart = n + 1;
    alive = 0;

    for (int i = n; i >= 1; i--)
    {
        if (minStart <= i)
        {
        }
        else
        {
            alive++;
        }
        long long start = (long long)i - L[i - 1];
        minStart = min(minStart, start);
    }

    cout << alive << "\n";
    return 0;
}