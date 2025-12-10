
static const long long MOD = 1000000007LL;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
      int n = (int)complexity.size();
        if (n == 0) return 0;
        // If any i > 0 has complexity[i] <= complexity[0], impossible
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) return 0;
        }
        // Otherwise answer = (n-1)! % MOD
        long long ans = 1;
        for (int k = 2; k <= n-1; ++k) ans = (ans * k) % MOD;
        // Note: if n==1, loop doesn't run and ans stays 1 (one permutation: [0])
        return (int)ans;  
    }
};