#include <bits/stdc++.h>
using namespace std;
int lexsmall(vector<int> &s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    vector<int> ss(s);
    ss.insert(ss.end(), s.begin(), s.end());
    vector<int> f(2 * n, -1);
    int k = 0;
    for (int j = 1; j < 2 * n; j++)
    {
        int sj = ss[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != ss[k + i + 1])
        {
            if (sj < ss[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if (sj != ss[k + i + 1])
        {
            if (sj < ss[k])
                k = j;
            f[j - k] = -1;
        }
        else
        {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        vector<int> LR, M;
        for (int i = 0; i < x; i++)
            LR.push_back(p[i]);
        for (int i = x; i < y; i++)
            M.push_back(p[i]);
        for (int i = y; i < n; i++)
            LR.push_back(p[i]);

        sort(LR.begin(), LR.end());

        int mid_size = M.size();
        int best_rot = lexsmall(M);

        for (int i = 0; i < x; i++)
            printf("%d ", LR[i]);
        for (int i = 0; i < mid_size; i++)
            printf("%d ", M[(best_rot + i) % mid_size]);
        for (int i = x; i < (int)LR.size(); i++)
            printf("%d ", LR[i]);
        printf("\n");
    }
}