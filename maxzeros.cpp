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

        int current = 0, maxZeros = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x == 0)
            {
                current++;
                if (current > maxZeros)
                    maxZeros = current;
            }
            else
            {
                current = 0;
            }
        }

        cout << maxZeros << endl;
    }

    return 0;
}
