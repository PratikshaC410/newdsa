

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
          int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n-1];
    
    // Rightmost element is always a leader
    leaders.push_back(maxFromRight);

    // Traverse from second last to first
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }

    // Reverse to maintain order of appearance
    reverse(leaders.begin(), leaders.end());
    return leaders; // Code here
        
    }
};