#include <iostream>
#include <string>
using namespace std;

bool isLucky(long long x)
{
    if (x == 0)
        return false;
    while (x > 0)
    {
        int d = x % 10;
        if (d != 4 && d != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main()
{
    string n;
    cin >> n;

    long long cnt = 0;
    for (char c : n)
    {
        if (c == '4' || c == '7')
        {
            cnt++;
        }
    }

    cout << (isLucky(cnt) ? "YES" : "NO") << endl;
    return 0;
}
