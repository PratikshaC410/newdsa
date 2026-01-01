#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int giver[101];

    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        giver[p] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << giver[i] << " ";
    }

    return 0;
}
