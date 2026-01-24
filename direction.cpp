#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int x = 0, y = 0;
        bool found = false;

        for (char c : s)
        {
            if (c == 'L')
                x--;
            else if (c == 'R')
                x++;
            else if (c == 'U')
                y++;
            else if (c == 'D')
                y--;

            if (x == 1 && y == 1)
            {
                found = true;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}
