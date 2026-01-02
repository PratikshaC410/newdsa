#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int avail_time = 240 - k;
    int time_spent = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        time_spent += 5 * i;
        if (time_spent > avail_time)
        {
            break;
        }
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}
