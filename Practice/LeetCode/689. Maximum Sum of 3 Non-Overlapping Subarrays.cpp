class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> preL(nums.size(),0),preR(nums.size()+1,0);
        vector<pair<int,int>> left(nums.size(),{0,-1}),right(nums.size()+1,{0,-1});
        int ans=0;
        vector<int> indices(3,0);
        for(int i=nums.size()-1;i>=0;i--){
            preR[i]=preR[i+1]+nums[i];
            if(nums.size()-i<k) continue;
            if(preR[i]-preR[i+k]>=right[i+1].first){
                right[i].first = preR[i]-preR[i+k];
                right[i].second = i;
            } else right[i]=right[i+1];
        }
        for(int i=0;i<nums.size();i++){
            if(i==0) preL[i]=nums[i];
            else preL[i]=preL[i-1]+nums[i];
            
            if(i<k-1) continue;
            else if(i==k-1){
                left[i].first=preL[i];
                left[i].second=i-k+1;
            } else{
                if(preL[i]-preL[i-k]>left[i-1].first){
                    left[i].first = preL[i]-preL[i-k];
                    left[i].second = i-k+1;
                } else left[i]=left[i-1];
                if(i>=2*k-1 && i+k<nums.size()){
                    int curr = left[i-k].first+preL[i]-preL[i-k]+right[i+1].first;
                    if(curr>ans){
                        ans=left[i-k].first+preL[i]-preL[i-k]+right[i+1].first;
                        indices[0]=left[i-k].second;
                        indices[1]=i-k+1;
                        indices[2]=right[i+1].second;
                    }
                }
            }
        }
        return indices;
    }
};