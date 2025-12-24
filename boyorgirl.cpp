#include <iostream>
using namespace std;

int main()
{
    string username;
    cin >> username;

    bool seen[256] = {false};
    int distinctCount = 0;

    for (char c : username)
    {
        if (!seen[c])
        {
            seen[c] = true;
            distinctCount++;
        }
    }

    if (distinctCount % 2 == 0)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";

    return 0;
}
