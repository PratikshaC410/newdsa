class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};
        for (int x : arr) {
            freq[x]++;
        }

        int ans = -1;

        for (int v = 500; v >= 1; v--) {
            if (freq[v] == v) {
                return v; 
            }
        }

        return -1; 
    }
};