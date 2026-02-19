#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int x = stoi(s);
        int k = sqrt(x);

        if (k * k == x)
        {
            cout << 0 << " " << k << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
