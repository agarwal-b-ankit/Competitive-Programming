class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(!minHeap.empty() && minHeap.top()<maxHeap.top()){
            int temp1 = minHeap.top();
            int temp2 = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            maxHeap.push(temp1);
            minHeap.push(temp2);
        }
        if(maxHeap.size()-minHeap.size()>1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()) return maxHeap.top();
        else return ((double)maxHeap.top()+minHeap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */