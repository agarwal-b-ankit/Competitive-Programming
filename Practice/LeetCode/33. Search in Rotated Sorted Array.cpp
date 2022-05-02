class Solution {
public:
    int search(vector<int> &nums, int left, int right, int target){
        if(left>right) return -1;
        int mid = (left + right)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[left]){
            if(target>=nums[left] && target<=nums[mid]) return search(nums,left,mid,target);
            else return search(nums,mid+1,right,target);
        } else{
            if(target>=nums[mid] && target<=nums[right]) return search(nums,mid,right,target);
            else return search(nums,left,mid-1,target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size()-1,target);
    }
};