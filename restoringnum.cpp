#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long x[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> x[i];
    }

    sort(x, x + 4);

    long long sum = x[3];

    long long a = sum - x[2];
    long long b = sum - x[1];
    long long c = sum - x[0];

    cout << a << " " << b << " " << c << endl;

    return 0;
}
