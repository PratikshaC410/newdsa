#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> prefixSumIndex;
        int maxLength = 0;
        int sum = 0;
        int n = arr.size();  // get the size of the vector

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                maxLength = i + 1;
            }

            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                int length = i - prefixSumIndex[sum];
                if (length > maxLength) {
                    maxLength = length;
                }
            } else {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLength;
    }
};
