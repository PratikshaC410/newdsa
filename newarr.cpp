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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> uniq;
        for (int i = 0; i < n; i++)
            if (i == 0 || a[i] != a[i - 1])
                uniq.push_back(a[i]);

        if (uniq.empty())
        {
            cout << 0 << "\n";
            continue;
        }

        int arrays = 1;
        int last = uniq[0];

        for (int i = 1; i < uniq.size(); i++)
        {
            if (uniq[i] > last + 1)
            {
                arrays++;
                last = uniq[i];
            }
            else
            {
            }
        }

        cout << arrays << "\n";
    }
    return 0;
}