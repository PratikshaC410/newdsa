#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a, maxValue = 0, total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a > maxValue)
            maxValue = a;
        total += a;
    }

    long long result = maxValue * n - total;

    cout << result << endl;

    return 0;
}
