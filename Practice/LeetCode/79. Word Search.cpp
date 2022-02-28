class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int i, int j, int ind, vector<vector<bool>> &vis){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] || word[ind]!=board[i][j]) return false;
        if(ind==word.size()-1) return true;
        
        vis[i][j]=true;
        bool flag = (search(board, word, i-1,j, ind+1, vis) || search(board, word, i,j-1, ind+1, vis) || search(board, word, i+1,j, ind+1, vis) || search(board, word, i,j+1, ind+1, vis));
        vis[i][j]=false;
        return flag;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && search(board, word, i, j, 0, vis))
                    return true;
            }
        }
        return false;
    }
};