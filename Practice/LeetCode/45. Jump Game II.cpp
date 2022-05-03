class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0;
        for(int i=nums.size()-1;i>0;){
            for(int j=0;j<i;j++){
                if(nums[j]>=i-j){
                    cnt++;
                    i=j;
                    break;
                }
            }
        }
        return cnt;
    }
};