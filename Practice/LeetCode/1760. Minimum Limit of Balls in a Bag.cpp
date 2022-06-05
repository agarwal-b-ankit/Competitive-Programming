class Solution {
private:
    bool isPossible(vector<int>& nums, int maxOperations, int maxPenalty){
        int ind = upper_bound(nums.begin(),nums.end(),maxPenalty)-nums.begin();
        int operations=0;
        for(;ind<nums.size();ind++)
            operations+=(nums[ind]-1)/maxPenalty;
        return operations<=maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(),nums.end());
        int left=1,right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid = (left+right)/2;
            if(isPossible(nums, maxOperations, mid)) right = mid;
            else left=mid+1;
        }
        return left;
    }
};