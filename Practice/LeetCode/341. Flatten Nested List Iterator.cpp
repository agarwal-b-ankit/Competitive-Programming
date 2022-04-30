/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    queue<int> flatList;
    
    void dfs(vector<NestedInteger> &nestedList){
        for(NestedInteger val:nestedList){
            if(val.isInteger()) flatList.push(val.getInteger());
            else dfs(val.getList());
        }
    }
public:
    vector<NestedInteger> nestedList;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        nestedList = nestedList;
        dfs(nestedList);
    }
    
    int next() {
        int val = flatList.front();
        flatList.pop();
        return val;
    }
    
    bool hasNext() {
        return !flatList.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */