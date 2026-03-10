#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int only1 = (b % 2 == c % 2) ? 1 : 0;
        int only2 = (a % 2 == c % 2) ? 1 : 0;
        int only3 = (a % 2 == b % 2) ? 1 : 0;

        cout << only1 << " " << only2 << " " << only3 << "\n";
    }

    return 0;
}