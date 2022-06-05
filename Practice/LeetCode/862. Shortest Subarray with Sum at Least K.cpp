class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        vector<long> pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++) pre[i]=pre[i-1]+nums[i-1];
        int ans=pre.size();
        for(int right=0;right<pre.size();right++){
            while(!dq.empty() && pre[dq.back()]>=pre[right])
                dq.pop_back();
            while(!dq.empty() && pre[right]-pre[dq.front()]>=k){
                ans=min(ans,right-dq.front());
                dq.pop_front();
            }
            dq.push_back(right);
        }
        return (ans<pre.size())?ans:-1;
    }
};