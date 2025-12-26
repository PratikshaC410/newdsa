#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int val = x / 5;
    int rem = x % 5;

    if (rem != 0)
        val++;

    cout << val << endl;
    return 0;
}
