class Solution {
  public:
    int minPlatform(vector<int> &arr, vector<int> &dep) {  // <-- renamed
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int plat_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            } else {
                plat_needed--;
                j++;
            }
            result = max(result, plat_needed);
        }
        return result;
    }
};
