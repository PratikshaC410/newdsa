#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> best = p;

        for (int i = 0; i <= n; i++)
        {
            vector<int> temp = p;
            reverse(temp.begin() + i, temp.end());
            if (temp > best)
            {
                best = temp;
            }
        }

        for (int x : best)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
