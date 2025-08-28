#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // done, no carry needed
            }
            digits[i] = 0; // set to 0 and carry over
        }
        
        // If all digits were 9, we need an extra 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
