#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string b;
        cin >> b;

        string a;
        a.push_back(b[0]);
        for (int i = 1; i < (int)b.size(); i += 2)
        {
            a.push_back(b[i]);
        }

        cout << a << "\n";
    }

    return 0;
}
