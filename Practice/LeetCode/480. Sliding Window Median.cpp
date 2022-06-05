class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> maxHeap;
        multiset<int> minHeap;
        vector<double> result;
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                int remove = nums[i-k];
                if(minHeap.find(remove)!=minHeap.end()){
                    minHeap.erase(minHeap.find(remove));
                } else{
                    maxHeap.erase(maxHeap.find(remove));
                }
                if(maxHeap.size()>1+minHeap.size()){
                    auto it = maxHeap.end();
                    it--;
                    minHeap.insert(*it);
                    maxHeap.erase(it);
                } else if(maxHeap.size()<minHeap.size()){
                    maxHeap.insert(*minHeap.begin());
                    minHeap.erase(minHeap.begin());
                }
            }
            maxHeap.insert(nums[i]);
            if(!minHeap.empty() && *maxHeap.rbegin()>*minHeap.begin()){
                // swap
                int maxTop = *maxHeap.rbegin();
                int minTop = *minHeap.begin();
                auto it = maxHeap.end();
                it--;
                maxHeap.erase(it);
                minHeap.erase(minHeap.begin());
                maxHeap.insert(minTop);
                minHeap.insert(maxTop);
            }
            if(maxHeap.size()>1+minHeap.size()){
                auto it = maxHeap.end();
                it--;
                minHeap.insert(*it);
                maxHeap.erase(it);
            }
            if(i<k-1) continue;
            if(maxHeap.size()>minHeap.size()) result.push_back(*maxHeap.rbegin());
            else result.push_back(((long)(*maxHeap.rbegin())+*minHeap.begin())/2.0);
        }
        return result;
    }
};