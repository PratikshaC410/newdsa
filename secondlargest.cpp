class Solution {
public:
    int getSecondLargest(vector<int> &a) {
        int largest = INT_MIN;
        int second = INT_MIN;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] > largest) {
                second = largest;
                largest = a[i];
            } else if (a[i] > second && a[i] != largest) {
                second = a[i];
            }
        }

        // If second is still INT_MIN, it means no second largest exists
        return (second == INT_MIN ? -1 : second);
    }
};
