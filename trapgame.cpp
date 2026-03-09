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

        string row1, row2;
        cin >> row1 >> row2;

        bool blocked = false;
        for (int j = 0; j < n; j++)
        {
            if (row1[j] == '1' && row2[j] == '1')
            {
                blocked = true;
                break;
            }
        }

        cout << (blocked ? "NO" : "YES") << "\n";
    }

    return 0;
}