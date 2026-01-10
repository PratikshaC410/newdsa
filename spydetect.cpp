#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[101];
        int x = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            x ^= a[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
