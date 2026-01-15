#include <iostream>
using namespace std;

void heapify(int H[], int n; int k)
{
    int v = H[k];
    while (2 * k <= n)
    {
        int j = 2 * k;
        if (j < n)
        {
            if (H[i] < H[j + 1])
                j++;
        }
        if (v >= H[k])
            break;
        else
        {
            H[j] = H[k];
            k = j;
        }
    }
    H[k] = v;
}

void buildheap(int H[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
    {
        heapif(H, n, i);
    }
}

void heapsort(int H[], int n)
{
    buildheap(H, n);

    for (int size = n; size > 1; size--)
    {

        swap(H[1], H[size]);

        heapify(H, size - 1, 1);
    }
}
int main()
{
    int n;
    cin >> n;

    int H[100];
    for (int i = 1; i <= n; i++)
        cin >> H[i];

    heapsort(H, n);

    for (int i = 1; i <= n; i++)
        cout << H[i] << " ";

    return 0;
}
