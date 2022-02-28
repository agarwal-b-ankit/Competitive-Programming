class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(4,0);
        for(auto i:nums) cnt[i]++;
        int n=nums.size(),i=n-1,j;
        for(int k=2;k>=0;k--){
            j = i-cnt[k];
            for(int c=0;c<cnt[k];c++,i--){
                if(nums[i]==k) continue;
                else{
                    while(j>=0){
                        if(nums[j]==k){
                            tie(nums[i],nums[j])=make_tuple(nums[j],nums[i]);
                            j--;
                            break;
                        }
                        j--;
                    }
                }
            }
        }
    }
};