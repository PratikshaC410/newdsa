class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
          vector<int> result;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=nums.front();i<nums.back();i++){
            if(i!=nums[j]){
                result.push_back(i);
            }else{
                j+=1;
            }
        }
        return result;
    }
};