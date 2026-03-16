#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int l = 0, r = n - 1;
    long long timeA = 0, timeB = 0;
    int a = 0, b = 0;

    while (l <= r)
    {
        if (timeA <= timeB)
        {
            timeA += t[l++];
            a++;
        }
        else
        {
            timeB += t[r--];
            b++;
        }
    }

    cout << a << " " << b << "\n";
    return 0;
}