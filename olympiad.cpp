#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> p, m, s;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
            p.push_back(i);
        else if (t == 2)
            m.push_back(i);
        else
            s.push_back(i);
    }

    int w = min({(int)p.size(), (int)m.size(), (int)s.size()});
    cout << w << endl;

    for (int i = 0; i < w; i++)
    {
        cout << p[i] << " " << m[i] << " " << s[i] << endl;
    }

    return 0;
}
