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
        string a;
        cin >> a;

        int m;
        cin >> m;
        string b, c;
        cin >> b >> c;

        deque<char> dq(a.begin(), a.end());

        for (int i = 0; i < m; ++i)
        {
            if (c[i] == 'V')
                dq.push_front(b[i]);
            else
                dq.push_back(b[i]);
        }

        for (char ch : dq)
            cout << ch;
        cout << '\n';
    }

    return 0;
}
