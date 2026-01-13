#include <iostream>
using namespace std;

int main()
{
    int n, v, arr[50];
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
    {
        v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
    cout << "the sorted array is" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
