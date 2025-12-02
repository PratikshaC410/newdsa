class Solution {
public:
    static const long long MOD = 1'000'000'007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> freq;
        freq.reserve(points.size() * 2);

        for (auto &p : points) {
            freq[p[1]]++;
        }

        vector<long long> segs;
        segs.reserve(freq.size());
        for (auto &e : freq) {
            long long k = e.second;
            if (k >= 2) {
                long long c = (k * (k - 1) / 2) % MOD;
                segs.push_back(c);
            }
        }

        if (segs.size() < 2) return 0;

        long long ans = 0, prefix = 0;
        for (long long s : segs) {
            ans = (ans + prefix * s) % MOD;
            prefix = (prefix + s) % MOD;
        }

        return (int)(ans % MOD);
    }
};
