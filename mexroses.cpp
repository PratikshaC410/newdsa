#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        int missing = 0;
        for (int i = 0; i < k; i++)
        {
            if (freq[i] == 0)
                missing++;
        }

        int extra_k = freq[k];

        cout << max(missing, extra_k) << "\n";
    }
    return 0;
}