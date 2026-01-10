#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int differentDays = min(a, b);
    int sameDays = abs(a - b) / 2;

    cout << differentDays << " " << sameDays << endl;

    return 0;
}
