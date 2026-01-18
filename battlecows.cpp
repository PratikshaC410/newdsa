#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        int N = 1 << n;

        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];

        // Precompute prefix XOR blocks
        vector<vector<int>> blockXOR(n + 1, vector<int>(N));
        for (int i = 0; i < N; i++)
            blockXOR[0][i] = a[i];

        for (int lvl = 1; lvl <= n; lvl++)
        {
            int len = 1 << lvl;
            for (int i = 0; i < N; i += len)
            {
                int x = 0;
                for (int j = 0; j < len; j++)
                {
                    x ^= blockXOR[0][i + j];
                }
                blockXOR[lvl][i] = x;
            }
        }

        while (q--)
        {
            int b, c;
            cin >> b >> c;
            b--; // 0-based

            int curX = c;
            int res = 0;

            for (int lvl = 0; lvl < n; lvl++)
            {
                int blockSize = 1 << lvl;
                int blockStart = (b >> lvl) << lvl;

                bool isLeft = (((b >> lvl) & 1) == 0);
                int oppStart = isLeft
                                   ? blockStart + blockSize
                                   : blockStart - blockSize;

                int oppX = blockXOR[lvl][oppStart];

                if (curX < oppX)
                    break;

                res += blockSize;
                curX ^= oppX;
            }

            cout << res << "\n";
        }
    }
    return 0;
}
