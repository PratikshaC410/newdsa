int missingNum(int *arr, int size) {
    int sum1 = 0, sum2 = 0, missnum;

    // Sum of elements in the array
    for (int i = 0; i < size; i++) {
        sum1 += arr[i];
    }

    // Sum of numbers from 1 to n
    int n = size + 1; // Because size = n-1
    for (int i = 1; i <= n; i++) {
        sum2 += i;
    }

    // Missing number
    missnum = sum2 - sum1;
    return missnum;
}
