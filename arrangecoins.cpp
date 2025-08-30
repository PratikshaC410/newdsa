class Solution {
public:
    int arrangeCoins(int n) {
        // use long long to avoid overflow in calculation
        long long left = 0, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coins = mid * (mid + 1) / 2;
            if (coins == n) return (int)mid;
            if (coins < n) left = mid + 1;
            else right = mid - 1;
        }
        return (int)right; // right is the largest k with k(k+1)/2 <= n
    }
};
