class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = (int)s.size();
        vector<int> zeroPos;
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeroPos.push_back(i);
        int Z = (int)zeroPos.size();
        long long ans = 0;

        long long run = 0;
        for (char c : s) {
            if (c == '1') ++run;
            else { ans += run * (run + 1) / 2; run = 0; }
        }
        ans += run * (run + 1) / 2;

        int MAXZ = (int)(sqrt(n)) + 2;
        // Case K >= 1
        for (int K = 1; K <= MAXZ && K <= Z; ++K) {
            for (int i = 0; i + K - 1 < Z; ++i) {
                int Lz = zeroPos[i];
                int Rz = zeroPos[i + K - 1];

                int leftLimit  = (i == 0 ? 0 : zeroPos[i - 1] + 1);
                int rightLimit = (i + K == Z ? n - 1 : zeroPos[i + K] - 1);

                int minLength = K * K + K;
                for (int L = leftLimit; L <= Lz; ++L) {
                    long long minR = (long long)L + minLength - 1;
                    long long actualMinR = max<long long>(Rz, minR);
                    if (actualMinR <= rightLimit) {
                        ans += (rightLimit - actualMinR + 1);
                    }
                }
            }
        }

        return ans;
    }
};