class Solution {
private:
    unordered_map<string,multiset<string>> graph;
    vector<string> result;
    
    void dfs(string source){
        while(!graph[source].empty()){
            auto it = graph[source].begin();
            string next = *it;
            graph[source].erase(it);
            dfs(next);
        }
        result.push_back(source);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket:tickets)
            graph[ticket[0]].insert(ticket[1]);
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};