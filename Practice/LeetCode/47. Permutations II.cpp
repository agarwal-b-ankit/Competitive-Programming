class Solution {
private:
    vector<vector<int>> result;
    void permuteAll(vector<int>& nums, int ind, map<int,int>& freq, vector<int>& curr){
        if(ind==nums.size()){
            result.push_back(curr);
            return;
        }
        for(auto it:freq){
            if(it.second==0) continue;
            freq[it.first]--;
            curr.push_back(it.first);
            permuteAll(nums,ind+1,freq, curr);
            curr.pop_back();
            freq[it.first]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> freq;
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        permuteAll(nums, 0, freq, temp);
        return result;
    }
};