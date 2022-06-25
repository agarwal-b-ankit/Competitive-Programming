class Solution {
private:
    static bool comp(pair<int,string> &p1, pair<int,string> &p2){
    if(p1.first==p2.first) return p1.second>p2.second;
    else return p1.first<p2.first;
}
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(&comp)> pq(comp);
        unordered_map<string,int> m;
        for(auto& word:words) m[word]++;
        for(auto e:m) pq.push({e.second,e.first});
        vector<string> result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};