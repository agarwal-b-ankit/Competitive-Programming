#define MAXN 100010
class Solution {
private:
    int bit[MAXN];
    int query(int ind){
        int sum = 0;
        for(;ind>0;ind-=ind&(-ind))
            sum+=bit[ind];
        return sum;
    }
    void update(int ind, int val){
        for(;ind<MAXN;ind+=ind&(-ind))
            bit[ind]+=val;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> pre(nums.size()+1,0);
        // ensuring 0 is also added as a prefix
        for(int i=1;i<=nums.size();i++)
            pre[i]=pre[i-1]+nums[i-1];
        // compress the prefix sum values so that we can store them in BIT
        sort(pre.begin(),pre.end());
        unordered_map<long, int> m;
        int ind=1;
        for(auto num:pre) m[num]=ind++;
        // add empty prefix to the BIT
        update(m[0],1);
        int ans=0;
        long cum=0;
        for(int i=0;i<nums.size();i++){
            cum+=nums[i]; // cumulative sum till i
            
            // get count of substring ending at i which has sum<=upper, or
            // get count of prefixes substracting which from cumulative sum would give sum <=upper
            int upperCnt=0;
            int upperInd = upper_bound(pre.begin(),pre.end(),cum-upper-1)-pre.begin();
            if(upperInd==0) upperCnt = i+1;
            else upperCnt = i+1-query(m[pre[upperInd-1]]);
            
            // get count of substring ending at i which has sum<lower, or
            // get count of prefixes substracting which from cumulative sum would give sum <lower
            int lowerCnt=0;
            int lowerInd = upper_bound(pre.begin(),pre.end(),cum-lower)-pre.begin();
            if(lowerInd==0) lowerCnt=i+1;
            else lowerCnt = i+1-query(m[pre[lowerInd-1]]);            
            
            ans+=upperCnt-lowerCnt;
            // add cumulative sum to the BIT
            update(m[cum],1);
        }
        return ans;
    }
};