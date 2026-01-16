#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    set<int> unique_elements;
    bool has_duplicate = false;

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        if (unique_elements.count(val))
        {
            has_duplicate = true;
        }
        unique_elements.insert(val);
    }

    if (has_duplicate)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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