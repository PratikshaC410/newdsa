#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long hao = 0;

        while (n >= 3)
        {
            long long m1 = n / 3;
            long long m2 = n / 3;
            long long m3 = n - m1 - m2;

            hao += m1;
            n = m3;
        }

        cout << hao << "\n";
    }
}