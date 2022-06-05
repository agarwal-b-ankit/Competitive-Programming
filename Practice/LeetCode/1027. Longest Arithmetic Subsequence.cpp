class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(1001,0));
        int ans=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j]+500;
                dp[i][diff]=max(dp[i][diff], 1 + dp[j][diff]);
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans+1;
    }
};