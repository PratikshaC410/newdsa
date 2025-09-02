class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
       vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        int idx = abs(arr[i]) - 1; // map value to index
        if (arr[idx] < 0) {
            // already visited -> duplicate
            result.push_back(abs(arr[i]));
        } else {
            // mark as visited
            arr[idx] = -arr[idx];
        }
    }
    return result; // code here
        
    }
};