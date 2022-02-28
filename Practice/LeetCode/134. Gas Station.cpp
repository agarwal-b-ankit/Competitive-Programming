class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot=0, curr=0, start=0;
        for(int i=0;i<gas.size();i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                tot+=curr;
                curr=0;
                start=i+1;
            }
        }
        return (curr+tot<0)?-1:start;
    }
};