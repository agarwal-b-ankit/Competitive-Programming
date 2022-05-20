class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        auto minMax = minmax_element(nums.begin(),nums.end());
        int bSize = (*minMax.second-*minMax.first)/nums.size() +1;
        vector<pair<int,int>> bucket(nums.size(),{INT_MAX,INT_MIN});
        for(int num:nums){
            int ind = (num-*minMax.first)/bSize;
            bucket[ind].first=min(bucket[ind].first,num);
            bucket[ind].second=max(bucket[ind].second,num);
        }
        int ans=0,prevMax=bucket[0].second;
        for(int i=1;i<nums.size();i++){
            if(bucket[i].first==INT_MAX) continue;
            ans=max(ans,bucket[i].first-prevMax);
            prevMax=bucket[i].second;
        }
        return ans;
    }
};