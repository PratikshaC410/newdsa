class Solution {
public:
    
    int minLengthAfterRemovals(std::string s) {
        // Count the occurrences of 'a' and 'b'
        long long count_a = 0;
        long long count_b = 0;

        for (char c : s) {
            if (c == 'a') {
                count_a++;
            } else { // c must be 'b'
                count_b++;
            }
        }

        // The minimum possible length is the absolute difference between the counts.
        // This is because the net balance (count_a - count_b) is an invariant 
        // under the allowed removal operation.
        long long min_length = std::abs(count_a - count_b);

        // Since the return type is int, we cast or ensure the result fits.
        // Given the constraints on string length (typically < 10^5 or 10^6), 
        // the difference will fit within an 'int'.
        return (int)min_length;
    }
};
