#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int height = 0;
    int level = 1;

    while (true)
    {
        int needed = level * (level + 1) / 2;
        if (n >= needed)
        {
            n -= needed;
            height++;
            level++;
        }
        else
        {
            break;
        }
    }

    cout << height << endl;
    return 0;
}
