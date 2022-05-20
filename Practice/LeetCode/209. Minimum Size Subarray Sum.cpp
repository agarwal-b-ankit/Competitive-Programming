class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen=nums.size()+1;
        long currSum=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            currSum+=nums[right];
            if(currSum>=target){
                minLen=min(minLen,right-left+1);
            }
            while(left<=right && currSum>=target){
                currSum-=nums[left++];
                if(currSum>=target){
                    minLen=min(minLen,right-left+1);
                } else break;
            }
        }
        if(minLen==nums.size()+1) return 0;
        else return minLen;
    }
};