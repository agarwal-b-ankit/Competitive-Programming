class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(1,nums[0]);
        for(int i=1;i<nums.size();i++){
            int ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
            if(ind==lis.size()){
                lis.push_back(nums[i]);
            } else if(lis[ind]>nums[i]){
                lis[ind]=nums[i];
            }
        }
        return lis.size();
    }
};