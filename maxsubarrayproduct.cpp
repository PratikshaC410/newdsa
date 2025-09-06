class Solution {
  public:
    int maxProduct(vector<int> &arr) {
       int n = arr.size();
    int result = arr[0];
    int currMax = arr[0];
    int currMin = arr[0];
    
    for (int i = 1; i < n; i++) {
        int num = arr[i];
        
        
        int tempMax = max({num, currMax * num, currMin * num});
        int tempMin = min({num, currMax * num, currMin * num});
        
        currMax = tempMax;
        currMin = tempMin;
        
        result = max(result, currMax);
    }
    
    return result;
    }
};