#include <iostream>
#include <string>
#include <set>
using namespace std;

bool distinctDigits(int x)
{
    string s = to_string(x);
    set<char> st(s.begin(), s.end());
    return st.size() == s.size();
}

int main()
{
    int y;
    cin >> y;

    for (int year = y + 1;; ++year)
    {
        if (distinctDigits(year))
        {
            cout << year << endl;
            break;
        }
    }

    return 0;
}
