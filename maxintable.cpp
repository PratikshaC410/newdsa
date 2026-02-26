#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[11][11] = {};
    for (int i = 1; i <= n; i++)
        a[i][1] = a[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1];
    long long mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mx = max(mx, a[i][j]);
    cout << mx << "\n";
}