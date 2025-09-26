                
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

bool canJump(vector<int>& nums) {
   
    int maxIndex = 0;

    for(int i = 0; i < nums.size(); i++){
      
        if (i > maxIndex){
            return false;
        }

        maxIndex = max(maxIndex, i + nums[i]);
    }
    
    return true;
}

int main() {
    vector<int> nums = {4, 3, 7, 1, 2};
    
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    bool ans = canJump(nums);
    
    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }
    
    return 0;
}