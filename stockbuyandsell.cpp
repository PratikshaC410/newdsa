class Solution {
public:

    int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);                  // keep track of lowest price
            maxProfit = max(maxProfit, price - minPrice);     // calculate profit if sold today
        }

        return maxProfit;
    }
};