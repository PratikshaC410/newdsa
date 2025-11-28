class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur, next;

        for (int x : arr) {
            next.clear();

            // Start a new subarray at index i
            next.insert(x);

            // Extend all previous subarrays by OR-ing with x
            for (int v : cur) {
                next.insert(v | x);
            }

            // Update current OR set
            cur = next;

            // Add all to global set
            for (int v : cur) ans.insert(v);
        }

        return ans.size();
    }
};
