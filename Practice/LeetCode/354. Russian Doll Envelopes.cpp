class Solution {
private:
    static bool compare(vector<int>& a1, vector<int>& a2){
        if(a1[0]==a2[0]) return a1[1]>a2[1];
        else return a1[0]<a2[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> lis;
        for(auto &envelope: envelopes){
            int ht = envelope[1];
            int ind = lower_bound(lis.begin(),lis.end(),ht)-lis.begin();
            if(ind==lis.size()) lis.push_back(ht);
            else lis[ind]=ht;
        }
        return lis.size();
    }
};