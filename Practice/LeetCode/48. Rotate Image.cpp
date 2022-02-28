class Solution {
public:
    void swap(vector<vector<int>>& matrix, int i, int j){
        int n = matrix.size();
        int temp = matrix[i][j];
        matrix[i][j]=matrix[n-1-j][i];
        matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
        matrix[j][n-1-i]=temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size()-i-1;j++){
                swap(matrix, i, j);
            }
        }
    }
};