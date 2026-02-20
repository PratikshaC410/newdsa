#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long result = (1LL << (n / 2 + 1)) - 2;
        cout << result << endl;
    }

    return 0;
}