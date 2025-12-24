#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string digits = "";
    for (char c : s)
    {
        if (c != '+')
            digits += c;
    }

    sort(digits.begin(), digits.end());

    for (int i = 0; i < digits.size(); i++)
    {
        if (i > 0)
            cout << "+";
        cout << digits[i];
    }

    return 0;
}
