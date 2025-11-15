class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> ones1, ones2;
        int n = img1.size();
        
        // collect coordinates of ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.emplace_back(i, j);
                if (img2[i][j] == 1) ones2.emplace_back(i, j);
            }
        }

        unordered_map<long long, int> shiftCount;
        int maxOverlap = 0;

        for (auto &p : ones1) {
            for (auto &q : ones2) {
                long long dx = q.first - p.first;
                long long dy = q.second - p.second;

                long long key = (dx << 32) | (dy & 0xffffffff);

                maxOverlap = max(maxOverlap, ++shiftCount[key]);
            }
        }

        return maxOverlap;
    }
};
