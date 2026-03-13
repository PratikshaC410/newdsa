#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxBench = *max_element(a.begin(), a.end());

    int maxK = maxBench + m;

    int lo = maxBench;
    int hi = maxK;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        int slots = 0;
        for (int i = 0; i < n; i++)
            slots += max(0, mid - a[i]);

        if (slots >= m)
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << " " << maxK << endl;
}