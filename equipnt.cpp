class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
       int n = arr.size();
    long long totalSum = 0, leftSum = 0;

    // Calculate total sum
    for (int num : arr) totalSum += num;

    // Traverse and check equilibrium
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i]; // now totalSum is right sum
        if (leftSum == totalSum) return i;
        leftSum += arr[i];
    }
    
    return -1; // code here
        
    }
};