#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        int l = 0, r = n - 1;
        int pos = n - 1;

        while (l <= r)
        {
            int leftSq = nums[l] * nums[l];
            int rightSq = nums[r] * nums[r];

            if (leftSq > rightSq)
            {
                result[pos--] = leftSq;
                l++;
            }
            else
            {
                result[pos--] = rightSq;
                r--;
            }
        }

        return result;
    }
};
