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
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int maxi = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= maxi)
            {
                maxi = a[i];
                cnt++;
            }
        }
        cout << n - cnt << "\n";
    }
}