#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnta = 0, cntd = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            cnta++;
        else
            cntd++;
    }

    if (cnta > cntd)
        cout << "Anton";
    else if (cntd > cnta)
        cout << "Danik";
    else
        cout << "Friendship";

    return 0;
}
