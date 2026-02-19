#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
        {
            count++;
        }
        else
        {
            if (count >= 3)
            {
                ans += (count - 2);
            }
            count = 0;
        }
    }

    if (count >= 3)
    {
        ans += (count - 2);
    }

    cout << ans << endl;

    return 0;
}
