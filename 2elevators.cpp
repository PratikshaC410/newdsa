#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        long long t1 = abs(a - 1);
        long long t2 = abs(b - c) + abs(c - 1);

        if (t1 < t2)
        {
            cout << 1 << endl;
        }
        else if (t2 < t1)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }

    return 0;
}
