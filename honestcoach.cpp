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
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        sort(s.begin(), s.end());

        int answer = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            answer = min(answer, abs(s[i] - s[i - 1]));
        }

        cout << answer << "\n";
    }

    return 0;
}
