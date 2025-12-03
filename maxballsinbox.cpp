class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> box(50, 0); // digit sum max ~ 45
        
        int best = 0;
        for (int x = lowLimit; x <= highLimit; x++) {
            int sum = 0, y = x;
            while (y > 0) {
                sum += y % 10;
                y /= 10;
            }
            box[sum]++;
            best = max(best, box[sum]);
        }
        
        return best;
    }
};
