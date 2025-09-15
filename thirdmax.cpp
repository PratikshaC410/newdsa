class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num < first && num > second) {
                third = second;
                second = num;
            } else if (num < second && num > third) {
                third = num;
            }
        }

        if (third == LONG_MIN) {
            return static_cast<int>(first);
        } else {
            return static_cast<int>(third);
        }
    }
};