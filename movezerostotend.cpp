class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
         int n = arr.size();
        int j = -1;

        // Find the first zero
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                j = i;
                break;
            }
        }

        // If there are no zeroes, we're done
        if (j == -1) return;

        // Move non-zero elements forward
        for (int i = j + 1; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};