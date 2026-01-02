#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }

    string s;
    cin >> s;

    long long totalCalories = 0;
    for (char c : s)
    {
        totalCalories += a[c - '1'];
    }

    cout << totalCalories << endl;
    return 0;
}
