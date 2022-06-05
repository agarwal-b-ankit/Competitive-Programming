class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int len=0;len<nums.size();len++){
            for(int i=0,j=len;j<nums.size();i++,j++){
                // If kth ballon is the last balloon being burst among balloons i to j
                for(int k=i;k<=j;k++){
                    int left=(k>i)?dp[i][k-1]:0; // cost for bursting ballons i to k-1
                    int right=(k<j)?dp[k+1][j]:0; // cost for bursting ballons k+1 to j
                    // Baloon to the left of kth baloon after the baloons i to k-1 have been burst
                    int leftBalloon = (i>0)?nums[i-1]:1;
                    // Baloon to the right of kth baloon after the baloons k+1 to j have been burst
                    int rightBalloon = (j+1)<nums.size()?nums[j+1]:1;
                    dp[i][j]=max(dp[i][j],left+right+leftBalloon*nums[k]*rightBalloon);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};