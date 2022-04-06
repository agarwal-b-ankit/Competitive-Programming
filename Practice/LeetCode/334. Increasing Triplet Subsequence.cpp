class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto num:nums){
            if(num<=min1) min1=num;
            else if(num<=min2) min2=num;
            else return true;
        }
        return false;
    }
};