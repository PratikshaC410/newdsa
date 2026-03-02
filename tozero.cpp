#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (n % 2 == 0)
        {

            cout << (n + (k - 2)) / (k - 1) << "\n";
        }
        else
        {

            n -= k; // herer num will becode even then do first case operation only
            cout << 1 + (n + (k - 2)) / (k - 1) << "\n";
        }
    }

    return 0;
}