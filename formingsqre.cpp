#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> xs(4), ys(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> xs[i] >> ys[i];
        }

        int side = *max_element(xs.begin(), xs.end()) - *min_element(xs.begin(), xs.end());

        cout << side * side << '\n';
    }
    return 0;
}
