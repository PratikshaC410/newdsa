#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string r;
        cin >> r;
        int n = r.size();

        int totalS = 0;
        for (char c : r)
            if (c == 's')
                totalS++;

        int operations = 0;

        int i = 0;
        while (i < n)
        {
            if (r[i] == 'u')
            {
                int j = i;
                while (j < n && r[j] == 'u')
                    j++;

                int len = j - i;

                bool leftS = (i - 1 >= 0 && r[i - 1] == 's');
                bool rightS = (j < n && r[j] == 's');

                if (leftS && rightS)
                {
                    operations += max(0, len - 1);
                }
                else
                {
                    operations += len;
                }

                i = j;
            }
            else
            {
                i++;
            }
        }

        //  at least 2 s
        if (totalS < 2)
        {
            operations += (2 - totalS);
        }

        cout << operations << "\n";
    }

    return 0;
}