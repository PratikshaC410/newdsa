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

        int neg = 0, zer = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == -1)
                neg++;
            else if (x == 0)
                zer++;
        }

        int ops = zer;
        if (neg % 2 == 1)
            ops += 2;

        cout << ops << "\n";
    }
    return 0;
}