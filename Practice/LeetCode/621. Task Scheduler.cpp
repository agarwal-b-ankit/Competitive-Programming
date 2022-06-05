class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int freq[26]={0};
        for(auto task:tasks) freq[task-'A']++;
        for(int i=0;i<26;i++) if(freq[i]>0) pq.push(freq[i]);
        int time;
        for(time=1;;time++){
            if(!q.empty() && q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                if(top>1) q.push({top-1,time+n+1});
            }
            if(q.empty() && pq.empty()) return time;
        }
        return 0;
    }
};