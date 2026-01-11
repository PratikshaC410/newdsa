#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;

        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
                minPrice = prices[i];

            int profit = prices[i] - minPrice;

            if (profit > maxProfit)
                maxProfit = profit;
        }

        return maxProfit;
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;
    return 0;
}