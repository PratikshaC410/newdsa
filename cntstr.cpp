#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int countA = 0, countB = 0;

        for (int i = 0; i < 5; i++)
        {
            if (s[i] == 'A')
                countA++;
            else
                countB++;
        }

        if (countA > countB)
            cout << "A\n";
        else
            cout << "B\n";
    }

    return 0;
}
