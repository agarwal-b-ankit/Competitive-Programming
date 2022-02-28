class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i+2<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1, right = nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]==0){
                    vector<int> temp{nums[i],nums[left],nums[right]};
                    ans.push_back(temp);
                    while(left<right && nums[left]==nums[++left]);
                    while(right>left && nums[right]==nums[--right]);
                } else if(nums[left]+nums[right]+nums[i]<0){
                    left++;
                } else{
                    right--;
                }
            }
        }
        return ans;
    }
};