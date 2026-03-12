#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;

        bool found = false;

        long long cur = n;
        while (cur >= m)
        {
            if (cur == m)
            {
                found = true;
                break;
            }
            if (cur % 3 != 0)
                break;
            //  m <= cur/3, go left else  m <= 2*cur/3 go right

            cur = cur;
            break;
        }

        if (!found)
        {
            queue<long long> q;
            q.push(n);
            while (!q.empty())
            {
                long long x = q.front();
                q.pop();
                if (x == m)
                {
                    found = true;
                    break;
                }
                if (x % 3 == 0)
                {
                    long long a = x / 3, b = 2 * x / 3;
                    if (a >= m)
                        q.push(a);
                    if (b >= m)
                        q.push(b);
                }
            }
        }

        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}