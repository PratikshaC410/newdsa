#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> twoRepeated(vector<int>& arr) {
        int n = arr.size() - 2; // Since array size = n+2
        vector<int> result;
        
        for (int i = 0; i < arr.size(); i++) {
            int index = abs(arr[i]) - 1; // Map value to index
            
            if (arr[index] < 0) {
                // Already negative → number repeated
                result.push_back(abs(arr[i]));
                if (result.size() == 2) break; // Found both
            } else {
                arr[index] = -arr[index]; // Mark as visited
            }
        }
        
        return result;
    }
};
