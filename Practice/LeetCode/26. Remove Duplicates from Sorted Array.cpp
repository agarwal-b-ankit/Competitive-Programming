class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]!=nums[ind]) swap(nums[i],nums[++ind]);
        return ind+1;
    }
};