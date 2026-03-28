#include <bits/stdc++.h>
using namespace std;

long long calcSumPrefixMin(vector<long long> &a)
{
    long long sum = 0;
    long long prefix_min = LLONG_MAX;

    for (long long x : a)
    {
        prefix_min = min(prefix_min, x);
        sum += prefix_min;
    }

    return sum;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long minSum = calcSumPrefixMin(a);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                vector<long long> temp = a;
                temp[i] += temp[j];
                temp[j] = 0;

                long long sum = calcSumPrefixMin(temp);
                minSum = min(minSum, sum);
            }
        }

        cout << minSum << "\n";
    }

    return 0;
}