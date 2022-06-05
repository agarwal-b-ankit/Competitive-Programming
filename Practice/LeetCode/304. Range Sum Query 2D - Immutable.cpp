class NumMatrix {
private:
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            pre.push_back(vector<int>());
            int sum=0;
            for(int j=0;j<matrix[i].size();j++){
                sum+=matrix[i][j];
                if(i==0) pre[i].push_back(sum);
                else pre[i].push_back(pre[i-1][j]+sum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pre[row2][col2];
        if(row1>0) sum-=pre[row1-1][col2];
        if(col1>0) sum-=pre[row2][col1-1];
        if(row1>0 && col1>0) sum+=pre[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */