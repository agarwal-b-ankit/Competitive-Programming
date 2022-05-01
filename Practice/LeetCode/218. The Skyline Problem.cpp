class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int,int>> list;
        for(auto building:buildings){
            list.push_back({building[0],-building[2]});
            list.push_back({building[1],building[2]});
        }
        sort(list.begin(),list.end());
        multiset<int> pq;
        pq.insert(0);
        for(int i=0,prev=0;i<list.size();i++){
            int ind = list[i].first, ht = list[i].second;
            if(ht<0) pq.insert(-ht);
            else pq.erase(pq.find(ht));
            
            if(prev!=*pq.rbegin()){
                vector<int> temp{ind,*pq.rbegin()};
                ans.push_back(temp);
                prev=*pq.rbegin();
            }
        }
        return ans;
    }
};