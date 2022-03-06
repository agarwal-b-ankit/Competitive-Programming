class Trie {
private:
    Trie* child[26];
    bool isEnd; 
public:
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            this->child[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(int i=0;i<word.length();i++){
            if(curr->child[word[i]-'a']==nullptr){
                curr->child[word[i]-'a'] = new Trie();
            }
            curr=curr->child[word[i]-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(int i=0;i<word.length();i++){
            if(curr->child[word[i]-'a']==nullptr) return false;
            curr=curr->child[word[i]-'a'];
        }
        return curr->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(int i=0;i<prefix.length();i++){
            if(curr->child[prefix[i]-'a']==nullptr) return false;
            curr=curr->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */