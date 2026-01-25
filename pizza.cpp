#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;

        vector<pair<long long, long long>> houses(n);
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            houses[i].first = x;
        }
        for (int i = 0; i < n; i++)
        {
            long long y;
            cin >> y;
            houses[i].second = y;
        }

        // Sort houses by x-coordinate (must visit left-to-right)
        sort(houses.begin(), houses.end());

        long long total = 0;

        // A -> first house
        if (n > 0)
        {
            long long dx = houses[0].first - Ax; // Always positive
            long long dy = abs(houses[0].second - Ay);
            total += max(dx, dy); // Chebyshev distance
        }

        // Consecutive houses
        for (int i = 1; i < n; i++)
        {
            long long dx = houses[i].first - houses[i - 1].first; // Always positive
            long long dy = abs(houses[i].second - houses[i - 1].second);
            total += max(dx, dy);
        }

        // Last house -> B
        if (n > 0)
        {
            long long dx = Bx - houses[n - 1].first; // Always positive
            long long dy = abs(By - houses[n - 1].second);
            total += max(dx, dy);
        }
        else
        {
            total = max(Bx - Ax, abs(By - Ay));
        }

        cout << total << "\n";
    }
    return 0;
}
