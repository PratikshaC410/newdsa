#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    long long distressed = 0;

    for (int i = 0; i < n; i++)
    {
        char type;
        long long d;
        cin >> type >> d;

        if (type == '+')
        {
            x += d;
        }
        else
        {
            if (x >= d)
            {
                x -= d;
            }
            else
            {
                distressed++;
            }
        }
    }

    cout << x << " " << distressed << endl;

    return 0;
}
