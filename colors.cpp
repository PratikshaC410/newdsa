#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s, t;
    cin >> s >> t;

    int pos = 0; // 0-based index for current position

    for (char c : t)
    {
        if (s[pos] == c)
        {
            pos++;
        }
    }

    cout << pos + 1 << "\n"; // convert to 1-based
    return 0;
}
