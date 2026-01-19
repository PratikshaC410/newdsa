#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            sum += x;
        }

        long long root = sqrt(sum);
        if (root * root == sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
