#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int sc = s[0] - 'a';
    int sr = s[1] - '1';
    int tc = t[0] - 'a';
    int tr = t[1] - '1';

    vector<string> moves;

    int r = sr, c = sc;

    while (r != tr || c != tc)
    {
        string move = "";

        if (c < tc)
        {
            c++;
            move += "R";
        }
        else if (c > tc)
        {
            c--;
            move += "L";
        }

        if (r < tr)
        {
            r++;
            move += "U";
        }
        else if (r > tr)
        {
            r--;
            move += "D";
        }

        moves.push_back(move);
    }

    cout << moves.size() << "\n";
    for (auto &m : moves)
        cout << m << "\n";

    return 0;
}