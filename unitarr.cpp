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
        int neg = 0, pos = 0;
        for (auto &x : a)
        {
            cin >> x;
            if (x == -1)
                neg++;
            else
                pos++;
        }

        int ops = 0;
        if (neg % 2 == 1)
        {
            neg--;
            pos++;
            ops++;
        }

        while (pos < neg)
        {
            neg -= 2;
            pos += 2;
            ops += 2;
        }
        cout << ops << "\n";
    }
}