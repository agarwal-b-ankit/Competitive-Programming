class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start=-1,end=-1;
        for(int i=0,maxi=INT_MIN;i<nums.size();i++){
            if(nums[i]<maxi) end=i;
            else maxi=nums[i];
        }
        for(int i=nums.size()-1,mini=INT_MAX;i>=0;i--){
            if(nums[i]>mini) start=i;
            else mini=nums[i];
        }
        return start!=-1?end-start+1:0;
    }
};