class Trie {
public:
    Trie* child[26];
    string word;
    bool isEnd; 
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
        curr->word=word;
        curr->isEnd = true;
    }
};

class Solution {
    vector<string> result;
public:
    void dfs(vector<vector<char>>& board, int i, int j, Trie* node){
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]=='*') return;
        Trie* curr = node->child[board[i][j]-'a'];
        if(curr==nullptr) return;
        if(curr->isEnd){
            result.push_back(curr->word);
            curr->isEnd = false;
        }
        char temp = board[i][j];
        board[i][j]='*';
        dfs(board, i-1, j, curr);
        dfs(board, i+1, j, curr);
        dfs(board, i, j-1, curr);
        dfs(board, i, j+1, curr);
        board[i][j]=temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *node = new Trie();
        for(string word:words)
            node->insert(word);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board, i, j, node);
            }
        }
        return result;
    }
};