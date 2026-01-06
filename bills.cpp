#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    int bills[] = {100, 20, 10, 5, 1};
    long long count = 0;

    for (int bill : bills)
    {
        count += n / bill;
        n %= bill;
    }

    cout << count << endl;
    return 0;
}
