#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int minimum = min({x1, x2, x3});
    int maximum = max({x1, x2, x3});

    cout << maximum - minimum << endl;

    return 0;
}
