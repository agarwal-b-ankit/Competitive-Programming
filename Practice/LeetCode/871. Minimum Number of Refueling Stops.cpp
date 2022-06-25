class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stops=0;
        for(auto station:stations){
            while(!pq.empty() && startFuel<station[0]){
                startFuel+=pq.top();
                stops++;
                pq.pop();
            }
            if(startFuel<station[0]) return -1; // cannot reach current station
            pq.push(station[1]);
        }
        while(!pq.empty() && startFuel<target){
            startFuel+=pq.top();
            stops++;
            pq.pop();
        }
        if(startFuel>=target) return stops;
        else return -1;
    }
};