class Solution {
public:
    int partition(vector<int>& nums, map<int,int> &freq, int left, int right){
        int pivot = left + rand()%(right-left+1);
        int pivotValue = freq[nums[pivot]];
        swap(nums[pivot],nums[right]);
        int ind = left;
        for(int i=left;i<=right;i++){
            if(freq[nums[i]]<pivotValue){
                swap(nums[ind],nums[i]);
                ind++;
            }
        }
        swap(nums[right],nums[ind]);
        return ind;
    }
    
    void quickSelect(vector<int>& nums, map<int,int> &freq, int left, int right, int k){
        if(left==right) return;
        int pivot = partition(nums, freq, left, right);
        if(pivot==k){
            return;
        } else if(pivot<k){
            quickSelect(nums, freq, pivot+1, right, k);
        } else{
            quickSelect(nums, freq, left, pivot-1, k);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for(int num:nums)
            freq[num]++;
        vector<int> unique;
        for(pair<int,int> p:freq)
            unique.push_back(p.first);
        int n=unique.size();
        
        quickSelect(unique, freq, 0, n-1, n-k);
        
        vector<int> ans;
        for(int i=n-k;i<unique.size();i++)
            ans.push_back(unique[i]);
        return ans;
    }
};