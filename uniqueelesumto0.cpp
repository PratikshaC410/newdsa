class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;

        // If n is odd, include 0
        if (n % 2 == 1)
            res.push_back(0);

        // Add pairs (i and -i)
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }

        return res;
    }
};
