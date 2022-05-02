class Solution {
private:
    int search(vector<int> &nums, int left, int right){
        if(left==right) return left;
        int mid = (left + right)/2;
        if(nums[mid]>nums[mid+1]) return mid;
        if(nums[mid]>=nums[left]) return search(nums,mid+1,right);
        else return search(nums,left,mid-1);
    }
public:
    int findMin(vector<int>& nums) {
        int pivot = search(nums,0,nums.size()-1);
        return nums[(pivot+1)%nums.size()];
    }
};