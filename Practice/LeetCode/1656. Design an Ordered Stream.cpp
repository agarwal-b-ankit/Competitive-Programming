class OrderedStream {
private:
    vector<string> s;
    int curr;
public:
    OrderedStream(int n) {
        curr=1;
        s.resize(n+2);
    }
    
    vector<string> insert(int idKey, string value) {
        s[idKey]=value;
        vector<string> result;
        while(s[curr]!="")
            result.push_back(s[curr++]);
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */