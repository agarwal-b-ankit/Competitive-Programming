class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int maxN = 1;
        for(int j=0;j<nums.size();j++){
            maxN = max(maxN,nums[j]);
        }
        int ans = 0;
        for(int i=0;i<=1+log2(maxN);i++){
            int cnt1 = 0, cnt2 = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)) cnt1++;
                if(j&(1<<i)) cnt2++;
            }
            if(cnt1>cnt2) ans|=(1<<i);
        }
        return ans;
    }
    
    int findDuplicate2(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
    int findDuplicate(vector<int>& nums) {
        //return findDuplicate1(nums);
        return findDuplicate2(nums);
    }
    
};