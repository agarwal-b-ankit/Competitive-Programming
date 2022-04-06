class Solution {
public:
    int noOfElementsLessThan(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix[0].size()-1, cnt=0;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]<target){
                i++;
                cnt+=j+1;
            } else{
                j--;
            }
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix[matrix.size()-1][matrix[0].size()-1];
        while(left<=right){
            int mid = (left+right)/2;
            int num = noOfElementsLessThan(matrix, mid);
            if(num<k) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};