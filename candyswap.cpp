class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumA - sumB) / 2; // this must be integer

        unordered_set<int> setB(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            int y = x - delta;
            if (setB.count(y)) {
                return {x, y};
            }
        }
        return {}; // guaranteed at least one solution
    }
};
