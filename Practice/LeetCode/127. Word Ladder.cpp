class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> dict;
        for(string word:wordList){
            for(int i=0;i<word.length();i++){
                string temp = word.substr(0,i)+"*"+word.substr(i+1);
                if(dict.find(temp)==dict.end()){
                    vector<string> v;
                    dict[temp]=v;
                }
                dict[temp].push_back(word);
            }
        }
        queue<string> q;
        unordered_map<string, int> vis;
        int ans=1;
        q.push(beginWord);
        while(!q.empty()){
            int cnt = q.size();
            ans++;
            while(cnt--){
                string word = q.front();
                q.pop();
                vis[word]++;
                for(int i=0;i<word.length();i++){
                    string temp = word.substr(0,i)+"*"+word.substr(i+1);
                    for(string next:dict[temp]){
                        if(next==endWord) return ans;
                        if(vis[next]==0)
                            q.push(next);
                    }
                }
            }
        }
        return 0;
    }
};