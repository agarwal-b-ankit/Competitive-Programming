class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }
        if(i>=0){
            j=i;
            for(i=i+1;i<nums.size();i++){
                if(nums[i]<=nums[j]) break;
            }
            swap(nums[j],nums[i-1]);
            i=j;
        }
        for(i=i+1,j=nums.size()-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
    }
};