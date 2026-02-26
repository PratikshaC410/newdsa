#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> suffixMinSum(n);

        long long minEndingHere = arr[n - 1];
        suffixMinSum[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            minEndingHere = min((long long)arr[i], minEndingHere + arr[i]);
            suffixMinSum[i] = min(suffixMinSum[i + 1], minEndingHere);
        }

        for (int i = 0; i < n; i++)
        {
            cout << suffixMinSum[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}