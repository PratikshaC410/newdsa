#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        // Collect left and right segments
        vector<int> outer;

        // Left segment: [0 ... x-1]
        for (int i = 0; i < x; i++)
        {
            outer.push_back(p[i]);
        }

        // Right segment: [y ... n-1]
        for (int i = y; i < n; i++)
        {
            outer.push_back(p[i]);
        }

        // Sort the outer elements
        sort(outer.begin(), outer.end());

        // Rebuild answer
        vector<int> result(n);

        // Fill left with smallest x elements
        for (int i = 0; i < x; i++)
        {
            result[i] = outer[i];
        }

        // Middle stays unchanged: [x ... y-1]
        for (int i = x; i < y; i++)
        {
            result[i] = p[i];
        }

        // Remaining elements go to right
        int idx = x;
        for (int i = y; i < n; i++)
        {
            result[i] = outer[idx++];
        }

        // Output result
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}