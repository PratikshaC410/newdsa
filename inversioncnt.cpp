class Solution {
  public:
    // Helper function to merge two halves and count inversions
    long long mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp;  // Temporary array for merging
        int i = left;      // Left subarray pointer
        int j = mid + 1;   // Right subarray pointer
        long long inv_count = 0;
        
        // Merge process
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv_count += (mid - i + 1); // Count inversions
            }
        }

        // Copy remaining elements
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        
        // Copy merged elements back to original array
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return inv_count;
    }

    // Recursive merge sort function
    long long mergeSortAndCount(vector<int> &arr, int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            inv_count += mergeSortAndCount(arr, left, mid);
            inv_count += mergeSortAndCount(arr, mid + 1, right);
            inv_count += mergeAndCount(arr, left, mid, right);
        }
        return inv_count;
    }

    // Main function
    int inversionCount(vector<int> &arr) {
        return (int)mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
