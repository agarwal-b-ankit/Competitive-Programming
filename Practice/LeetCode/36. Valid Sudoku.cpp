class Solution {
public:
    bool valid(vector<char> temp){
        vector<int> v(10,0);
        for(auto ch:temp){
            if(v[ch-'0']>0) return false;
            v[ch-'0']=1;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> temp;
        for(int i=0;i<board.size();i++){
            temp.clear();
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.')
                    temp.push_back(board[i][j]);
            }
            if (!valid(temp)) return false;
        }
        for(int i=0;i<board.size();i++){
            temp.clear();
            for(int j=0;j<board.size();j++){
                if(board[j][i]!='.')
                    temp.push_back(board[j][i]);
            }
            if (!valid(temp)) return false;
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                temp.clear();
                for(int k=0;k<9;k++){
                    int r=i+k/3;
                    int c=j+k%3;
                    if(board[r][c]!='.')
                        temp.push_back(board[r][c]);
                }
                if (!valid(temp)) return false;
            }
        }
        return true;
    }
};