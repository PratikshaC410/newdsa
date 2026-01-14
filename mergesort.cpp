#include <iostream>
using namespace std;

void merge(int B[], int p, int C[], int q, int A[])
{
    int i, j, k;
    while (i < p && j < q)
    {
        if (B[i] < C[i])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    if (i == p)
    {
        while (j < q)
        {
            A[k] = C[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < p)
        {
            A[k] = B[i];
            i++;
            k++;
        }
    }
}

void mergesort(int A[], int n)
{
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        B[i] = A[i];
    }

    for (int i = mid; i < n; i++)
    {
        C[i - mid] = A[i];
    }
    mergesort(B, mid);
    mergesort(C, n - mid);
    merge(B, mid, C, n - mid, A);
}

int main()
{
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    int A[100];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    mergesort(A, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
