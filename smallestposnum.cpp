class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    int expected = 1;

    for (int num : arr) {
        if (num == expected) {
            expected++;
        } else if (num > expected) {
            return expected;
        }
        // if num < expected, ignore
    }
    return expected;
    }
};