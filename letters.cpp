#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    set<char> distinct;

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            distinct.insert(c);
        }
    }

    cout << distinct.size() << endl;
    return 0;
}
