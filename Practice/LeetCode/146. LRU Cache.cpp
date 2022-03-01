class LRUCache {
private:
    list<pair<int,int>> keyList;
    unordered_map<int,list<pair<int,int>>::iterator> keyMap;
    int size;
    
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(keyMap.find(key)==keyMap.end()) return -1;
        
        int value = (keyMap[key])->second;
        keyList.erase(keyMap[key]);
        keyList.push_front({key,value});
        keyMap[key]=keyList.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(keyMap.find(key)!=keyMap.end()){
            keyList.erase(keyMap[key]);
        } else if(size==keyMap.size()){
            keyMap.erase(keyList.rbegin()->first);
            keyList.pop_back();
        }
        keyList.push_front({key,value});
        keyMap[key]=keyList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */