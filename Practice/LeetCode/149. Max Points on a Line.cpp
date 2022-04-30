class Solution {
private:
    pair<int,int> getSlope(vector<int>& p1, vector<int>& p2){
        if(p1[0]==p2[0]) return {INT_MAX,INT_MAX};
        else if(p1[1]==p2[1]) return {0,0};
        int y = p1[1]-p2[1], x = p1[0]-p2[0];
        if(y<0){
            y*=-1;
            x*=-1;
        }
        int gcd = __gcd(abs(y),abs(x));
        return {y/gcd,x/gcd};
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            map<pair<int,int>,int> slopeMap;
            for(int j=i+1;j<points.size();j++){
                pair<int,int> slope = getSlope(points[i],points[j]);
                slopeMap[slope]++;
                ans=max(ans,slopeMap[slope]);
            }
        }
        return ans+1;
    }
};