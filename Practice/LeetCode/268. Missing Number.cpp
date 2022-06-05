class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorSum=0;
        for(auto num:nums)
            xorSum^=num;
        for(int i=0;i<=nums.size();i++)
            xorSum^=i;
        return xorSum;
    }
};