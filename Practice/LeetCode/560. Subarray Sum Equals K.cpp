class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(),0);
        int ans=0;
        map<int,int> freq;
        freq[0]=1;
        for(int i=0;i<nums.size();i++){
            if(i==0) pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
            ans+=freq[pre[i]-k];
            freq[pre[i]]++;
        }
        return ans;
    }
};