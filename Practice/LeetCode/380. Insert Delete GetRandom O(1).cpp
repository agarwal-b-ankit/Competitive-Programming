class RandomizedSet {
public:
    vector<int> items;
    unordered_map<int,int> pos;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(pos.find(val)!=pos.end()) return false;
        items.push_back(val);
        pos[val]=items.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(pos.find(val)==pos.end()) return false;
        int ind = pos[val];
        items[ind]=items[items.size()-1];
        pos[items[ind]]=ind;
        items.pop_back();
        pos.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand()%(items.size());
        return items[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */