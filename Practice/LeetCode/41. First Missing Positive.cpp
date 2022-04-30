class Solution {
private:
    int segregate(vector<int>& nums){
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                swap(nums[i],nums[pos++]);
        }
        return pos;
    }

public:
    int firstMissingPositive(vector<int>& nums) {
        long pos = segregate(nums);
        for(int i=0;i<pos;i++){
            long ind = abs(nums[i])-1;
            if(ind>=0 && ind<pos && nums[ind]>0)
                nums[ind]*=-1; 
        }
        for(int i=0;i<pos;i++){
            if(nums[i]>0)
                return i+1;
        }
        return pos+1;
    }
};