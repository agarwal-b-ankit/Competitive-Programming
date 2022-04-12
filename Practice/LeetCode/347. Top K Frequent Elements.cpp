class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int num:nums)
            m[num]++;
        for(pair<int,int> p:m){
            pq.push({p.second,p.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};