#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter the text" << endl;
    cin >> text;
    cout << "Enter the pattern" << endl;
    cin >> pattern;

    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
    return 0;
}
