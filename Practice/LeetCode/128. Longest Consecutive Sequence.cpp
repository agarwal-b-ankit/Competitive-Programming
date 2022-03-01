class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans = 0;
        unordered_map<int,int> m;
        for(auto e:nums) m[e]++;
        for(auto e:nums){
            if(m.find(e-1)==m.end()){
                int cnt=1;
                while(m.find(++e)!=m.end()){
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};