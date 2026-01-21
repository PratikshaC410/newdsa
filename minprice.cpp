#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        int pairCost = min(2 * a, b);
        int totalCost = (n / 2) * pairCost + (n % 2) * a;

        cout << totalCost << '\n';
    }
    return 0;
}
