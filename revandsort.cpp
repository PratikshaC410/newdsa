#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n), sorted;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (k >= 2)
        {
            cout << "YES\n";
        }
        else
        {
            sorted = a;
            sort(sorted.begin(), sorted.end());

            if (a == sorted)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
