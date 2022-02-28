class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& curr, vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(curr);
            return;
        }
        solve(nums,ind+1,curr,ans);
        curr.push_back(nums[ind]);
        solve(nums,ind+1,curr,ans);
        curr.pop_back();
    }
    
    vector<vector<int>> solveBitmask(vector<int>& nums){
        int n = pow(2,nums.size());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> curr;
            for(int j=0,num=i;num>0;j++,num/=2){
                if(num%2) curr.push_back(nums[j]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //vector<vector<int>> ans;
        //vector<int> curr;
        //solve(nums, 0, curr, ans);
        //return ans;
        return solveBitmask(nums);
    }
};