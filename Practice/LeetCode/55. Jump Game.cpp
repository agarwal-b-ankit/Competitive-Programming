class Solution {
public:
    bool canJump(vector<int>& nums, int ind, vector<int>& dp){
        if(dp[ind]!=-1) return dp[ind];
        if(ind+1==nums.size()){
            dp[ind]=1;
            return true;
        }
        int flag = 0;
        for(int i=1;i<=nums[ind] && ind+i<nums.size();i++){
            if(canJump(nums,ind+i,dp)){
                dp[ind]=1;
                return true;
            }
        }
        dp[ind]=0;
        return false;
    }
    
    bool canJump1(vector<int>& nums){
        int reachable = 0;
        for(int i=0;i<nums.size();i++){
            if(i>reachable) return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
    
    bool canJump(vector<int>& nums) {
        //vector<int> dp(nums.size(),-1);
        //return canJump(nums,0,dp);
        return canJump1(nums);
    }
};