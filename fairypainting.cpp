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
        set<int> colors;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            colors.insert(a);
        }
        while (true)
        {
            int c = colors.size();
            if (colors.count(c))
            {
                cout << c << "\n";
                break;
            }
            colors.insert(c);
        }
    }
    return 0;
}