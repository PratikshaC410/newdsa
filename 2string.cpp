#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); ++i)
    {
        char cs1 = tolower(s1[i]);
        char cs2 = tolower(s2[i]);
        if (cs1 < cs2)
        {
            cout << -1;
            return 0;
        }
        else if (cs1 > cs2)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
