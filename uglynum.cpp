class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;   // ugly numbers are positive only

        // Divide n by 2, 3, and 5 repeatedly
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        // If n becomes 1, it’s an ugly number
        return n == 1;
    }
};
