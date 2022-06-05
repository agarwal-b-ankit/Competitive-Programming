class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i+3<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j+2<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    long sum = 0L + nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]) left++;
                        while(right>left && nums[right]==nums[right+1]) right--;
                    } else if(sum<target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
};