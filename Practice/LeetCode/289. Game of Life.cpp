class Solution {
public:
    int getLiveNeighbors(vector<vector<int>> &board, int r, int c){
        int row[]={-1, -1, -1, 0, 0, 1, 1, 1};
        int col[]={-1, 0, 1, -1, 1, -1, 0, 1};
        int cnt = 0;
        for(int i=0;i<8;i++){
            if(r+row[i]<0 || r+row[i]>=board.size() || c+col[i]<0 || c+col[i]>=board[0].size()) continue;
            if(board[r+row[i]][c+col[i]]%2) cnt++;
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int live = getLiveNeighbors(board, i, j);
                if(board[i][j]==1 && (live<2 || live>3)) board[i][j]=3;
                else if(board[i][j]==0 && live==3) board[i][j]=2;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>1) board[i][j] = 1-board[i][j]%2;
            }
        }
    }
};