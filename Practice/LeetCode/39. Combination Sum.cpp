class Solution {
private:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, int ind, vector<int>& vec){
        if(ind==candidates.size()){
            if(target==0) result.push_back(vec);
            return;
        }
        solve(candidates,target,ind+1,vec);
        if(candidates[ind]<=target){
            vec.push_back(candidates[ind]);
            solve(candidates,target-candidates[ind],ind,vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,target,0,temp);
        return result;
    }
};