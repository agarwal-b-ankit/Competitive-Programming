class Solution {
public:
    void solve(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(board[i][j]=='O'){
            board[i][j]='o';
            solve(board, i,j-1);
            solve(board, i,j+1);
            solve(board, i-1,j);
            solve(board, i+1,j);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && board[i][j]=='O')
                    solve(board, i, j);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='o') board[i][j]='O';
            }
        }
    }
};