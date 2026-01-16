#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int count1 = 0, count2 = 0;
    int total_weight = 0;

    for (int i = 0; i < n; ++i)
    {
        int weight;
        cin >> weight;
        if (weight == 1)
            count1++;
        else
            count2++;
        total_weight += weight;
    }

    if (total_weight % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        int half = total_weight / 2;
        if (half % 2 != 0 && count1 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}