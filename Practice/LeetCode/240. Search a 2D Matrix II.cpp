class Solution {
public:
    bool search(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2, int target){
        if(r1>r2 || c1>c2 || matrix[r1][c1] > target || matrix[r2][c2] < target) return false;
        if(matrix[r1][c1]==target) return true;
        int r = (r1+r2)/2, c = (c1+c2)/2;
        return search(matrix, r1,c1,r,c,target) || search(matrix, r1,c+1,r,c2,target) || search(matrix, r+1, c1, r2,c,target) || search(matrix, r+1, c+1, r2, c2,target);
    }
    
    bool search(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(target>matrix[i][j]) i++;
            else if(target<matrix[i][j]) j--;
            else return true;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return search(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
        return search(matrix, target);
    }
};