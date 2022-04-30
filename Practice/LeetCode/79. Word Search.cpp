class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int i, int j, int ind){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[ind]!=board[i][j]) return false;
        if(ind==word.size()-1) return true;
        
        char temp = board[i][j];
        board[i][j]='*';
        bool flag = (search(board, word, i-1,j, ind+1) || search(board, word, i,j-1, ind+1) || search(board, word, i+1,j, ind+1) || search(board, word, i,j+1, ind+1));
        board[i][j]=temp;
        return flag;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && search(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};