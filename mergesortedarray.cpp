class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for nums1
        int j = n - 1;         // Pointer for nums2
        int k = m + n - 1;     // Pointer for the merged array (backward)

        // Merge nums2 into nums1 from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has elements, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy the remaining nums1 elements (already in place)
    }
};