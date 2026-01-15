#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int h, m;
        cin >> h >> m;

        int passed = h * 60 + m;
        int remaining = 1440 - passed;

        cout << remaining << "\n";
    }

    return 0;
}
