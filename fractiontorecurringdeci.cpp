class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";

        string result;

        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = llabs(numerator);
        long long den = llabs(denominator);

        long long integerPart = num / den;
        result += to_string(integerPart);

        long long rem = num % den;
        if (rem == 0) return result;

        result += ".";

        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                int pos = seen[rem];
                result.insert(pos, "(");
                result += ")";
                return result;
            }

            seen[rem] = result.size();

            rem *= 10;
            result += to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};
