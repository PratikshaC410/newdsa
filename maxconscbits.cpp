class Solution
{
public:
  int maxConsecBits(vector<int> &nums)
  {
    int cnto = 0, cntz = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        cnto++;
      }
      else
      {
        cnto = 0;
      }
      if (nums[i] == 0)
      {
        cntz++;
      }
      else
      {
        cntz = 0;
      }

      maxi = max(maxi, max(cnto, cntz));
    }
    return maxi;
  }
};