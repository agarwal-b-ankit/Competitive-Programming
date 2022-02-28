class Solution {
public:
    int search(vector<int>& nums, int target, bool flag){
        int left = 0, right = nums.size() -1, ans = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                ans=mid;
                if(flag) left = mid+1;
                else right=mid-1;
            } else if (nums[mid]<target){
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search(nums,target,false),search(nums,target,true)};
    }
};