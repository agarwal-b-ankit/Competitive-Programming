class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({nums1[0]+nums2[0],{0,0}});
        vector<vector<int>> result;
        while(!pq.empty() && k--){
            auto top = pq.top().second;
            pq.pop();
            result.push_back(vector<int>{nums1[top.first], nums2[top.second]});
            if(top.first+1<nums1.size()){
                pq.push({nums1[top.first+1]+nums2[top.second],{top.first+1,top.second}});
            }
            if(top.first==0 && top.second+1<nums2.size()){
                pq.push({nums1[top.first]+nums2[top.second+1],{top.first,top.second+1}});
            }
        }
        return result;
    }
};