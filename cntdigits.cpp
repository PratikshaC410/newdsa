class Solution {
  public:
    int evenlyDivides(int n) {
        int original = n;
        int count = 0;

        while (n > 0) {
            int digit = n % 10; // extract last digit
            n /= 10;            // remove last digit

            // ignore zero to avoid division by zero
            if (digit != 0 && original % digit == 0) {
                count++;
            }
        }

        return count;
    }
};
