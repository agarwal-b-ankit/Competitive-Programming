class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = left + rand()%(right-left+1);
        int pivotValue = nums[pivot];
        swap(nums[pivot],nums[right]);
        int ind = left;
        for(int i=left;i<=right;i++){
            if(nums[i]<pivotValue){
                swap(nums[ind],nums[i]);
                ind++;
            }
        }
        swap(nums[right],nums[ind]);
        return ind;
    }
    
    void quickSelect(vector<int>& nums, int left, int right, int k){
        if(left==right) return;
        int pivot = partition(nums, left, right);
        if(pivot==k){
            return;
        } else if(pivot<k){
            quickSelect(nums, pivot+1, right, k);
        } else{
            quickSelect(nums, left, pivot-1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        quickSelect(nums, 0, nums.size()-1, nums.size()-k);
        return nums[nums.size()-k];
    }
};