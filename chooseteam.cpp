#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    int eligible = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        if (y <= 5 - k)
        {
            eligible++;
        }
    }

    cout << eligible / 3 << "\n";
    return 0;
}
