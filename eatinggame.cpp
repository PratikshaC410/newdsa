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

        int a[11]; // n ≤ 10
        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > mx)
                mx = a[i];
        }

        int countMax = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == mx)
                countMax++;
        }

        cout << countMax << endl;
    }

    return 0;
}