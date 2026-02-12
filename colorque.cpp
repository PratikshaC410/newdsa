#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    bool isColor = false;
    char pixel;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> pixel;
            if (pixel == 'C' || pixel == 'M' || pixel == 'Y')
            {
                isColor = true;
            }
        }
    }

    if (isColor)
        cout << "#Color" << endl;
    else
        cout << "#Black&White" << endl;

    return 0;
}
