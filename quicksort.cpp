#include <iostream>
using namespace std;
int partition(int a[], int l, int r)
{
    int p = a[l];
    int i = l, j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < p);
        do
        {
            j--;
        } while (a[j] > p);

        if (i >= j)
            break;

        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);

    return j;
}

void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int s = partition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int a[100];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
