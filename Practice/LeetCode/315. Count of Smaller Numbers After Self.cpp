const int MAXN=100010;
class Solution {
public:
    int bit[MAXN];
    
    void update(int ind, int val){
        for(int i=ind;i<MAXN;i+=i&(-i)){
            bit[i]+=val;
        }
    }

    int query(int ind){
        int sum=0;
        for(int i=ind;i>0;i-=i&(-i)){
            sum+=bit[i];
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        memset(bit,0,sizeof(bit));
        for(int i=nums.size()-1;i>=0;i--){
            int val=nums[i]+10001;
            nums[i]=query(val-1);
            update(val,1);
        }
        return nums;
    }
};