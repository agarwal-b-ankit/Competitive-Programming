class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ansMax = nums[0], currMin = nums[0],currMax = nums[0];
        for(int i=1;i<nums.size();i++){
            int newMin = min(min(currMin*nums[i],currMax*nums[i]),nums[i]);
            currMax = max(max(currMin*nums[i],currMax*nums[i]),nums[i]);
            currMin=newMin;
            ansMax=max(ansMax,currMax);
        }
        return ansMax;
    }
};