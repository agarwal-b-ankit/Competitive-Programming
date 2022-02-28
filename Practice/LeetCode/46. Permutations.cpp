class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, vector<int>& flag, int pos, vector<int>& curr){
        if(pos==nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(flag[i]!=-1) continue;
            flag[i]=pos;
            curr.push_back(nums[i]);
            solve(nums,flag,pos+1, curr);
            curr.pop_back();
            flag[i]=-1;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> flag(nums.size(),-1);
        vector<int> curr;
        solve(nums,flag,0, curr);
        return res;
    }
};