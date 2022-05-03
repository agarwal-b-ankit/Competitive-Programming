class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(2001,0));
        dp[0][nums[0]+1000]=1;
        dp[0][-nums[0]+1000]+=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<2001;j++){
                if(j-nums[i]>=0 && j-nums[i]<2001)
                    dp[i][j]=dp[i-1][j-nums[i]];
                if(j+nums[i]>=0 && j+nums[i]<2001)
                    dp[i][j]+=dp[i-1][j+nums[i]];
            }
        }
        return dp[nums.size()-1][target+1000];
    }
};