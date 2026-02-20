int lastoccur(int arr[], int k)
{
    int low = 0, high = n - 1, mid, res;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            res = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return res;
}