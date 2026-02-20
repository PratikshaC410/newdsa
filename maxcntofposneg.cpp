class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int i, posnum = 0, negnum = 0;
        int n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                posnum++;
            else if (nums[i] == 0)
            {
                continue;
            }
            else
                negnum++;
        }
        int res = max(posnum, negnum);
        return res;
    }
};