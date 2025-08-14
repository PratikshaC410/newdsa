class Solution {
public:
    int maxArea(const vector<int>& h) {
        int i = 0, j = (int)h.size() - 1;
        long long best = 0; // use 64-bit for the product, cast back to int at the end

        while (i < j) {
            int height = (h[i] < h[j]) ? h[i] : h[j];
            long long area = 1LL * height * (j - i);
            if (area > best) best = area;

            // Move the pointer at the smaller height inward
            if (h[i] < h[j]) {
                int cur = h[i];
                // Optional skip of equal/shorter bars to reduce iterations slightly
                while (i < j && h[i] <= cur) ++i;
            } else {
                int cur = h[j];
                while (i < j && h[j] <= cur) --j;
            }
        }
        return (int)best;
    }
};
