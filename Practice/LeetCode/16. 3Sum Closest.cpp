class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX,ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum = nums[left]+nums[right]+nums[i];
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    ans=sum;
                }
                if(sum==target){
                    return sum;
                } else if(sum<target){
                    left++;
                } else right--;
            }
        }
        return ans;
    }
};