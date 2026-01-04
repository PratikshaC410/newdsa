#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    int l = 0, r = n - 1;
    int s = 0, d = 0;
    bool sTurn = true;

    while (l <= r)
    {
        int chosen;
        if (cards[l] > cards[r])
        {
            chosen = cards[l++];
        }
        else
        {
            chosen = cards[r--];
        }

        if (sTurn)
        {
            s += chosen;
        }
        else
        {
            d += chosen;
        }

        sTurn = !sTurn;
    }

    cout << s << " " << d << endl;
    return 0;
}
