#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int sleep = 0;
        int i = 0;

        while (i < n)
        {
            if (s[i] == '1')
            {
                i += k + 1;
            }
            else
            {
                sleep++;
                i++;
            }
        }

        cout << sleep << "\n";
    }

    return 0;
}