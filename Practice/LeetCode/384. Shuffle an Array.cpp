class Solution {
public:
    vector<int> original;
    vector<int> items;
    Solution(vector<int>& nums) {
        original = nums;
        items = nums;
    }
    
    vector<int> reset() {
        items = original;
        return items;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<items.size();i++){
            int ind = i+rand()%(items.size()-i);
            swap(items[i],items[ind]);
        }
        return items;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */