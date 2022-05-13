class Solution {
private:
    vector<vector<string>> result;
    
    bool canPlace(int row, int col, vector<string>& curr){
        for(int i=0;i<row;i++)
            if(curr[i][col]=='Q') return false;
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
            if(curr[i][j]=='Q') return false;
        for(int i=row-1,j=col+1;i>=0 && j<curr.size();i--,j++)
            if(curr[i][j]=='Q') return false;
        return true;
    }

    void placeQueen(int row, vector<string> curr){
        if(row==curr.size()){
            result.push_back(curr);
            return;
        }
        for(int col=0;col<curr.size();col++){
            if(canPlace(row,col,curr)){
                curr[row][col]='Q';
                placeQueen(row+1,curr);
                curr[row][col]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n,string(n,'.'));
        placeQueen(0,curr);
        return result;
    }
};