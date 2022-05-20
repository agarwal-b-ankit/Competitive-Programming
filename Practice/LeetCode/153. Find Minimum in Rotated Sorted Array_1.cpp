class Solution {
private:
    int search(vector<int> &nums, int low, int high){
        if(low==high) return nums[low];
        int mid = (low + high)/2;
        if(nums[mid]>=nums[low] && nums[mid]<nums[high]) return nums[low];
        else if(nums[mid]<nums[low]) return search(nums,low,mid);
        else return search(nums,mid+1,high);
    }
public:
    int findMin(vector<int>& nums) {
        return search(nums,0,nums.size()-1);
    }
};