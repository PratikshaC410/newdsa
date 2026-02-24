#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long s1 = 0, s2 = 0, layer = 1;
        int ans = 0;
        for (int i = 1; i <= 40; i++)
        {
            if (i % 2 == 1)
                s1 += layer;
            else
                s2 += layer;
            // s1=odd layers sum, s2=even layers sum

            if ((s1 <= a && s2 <= b) || (s1 <= b && s2 <= a))
                ans = i;
            layer *= 2;
        }
        cout << ans << "\n";
    }
}