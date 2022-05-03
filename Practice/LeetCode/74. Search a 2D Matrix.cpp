class Solution {
private:
	bool search1(vector<vector<int>>& matrix, int target, int left, int right){
        if(left>right) return false;
        int mid=(left+right)/2;
        int i=mid/matrix[0].size(),j=mid%matrix[0].size();
        if(target==matrix[i][j]) return true;
        else if (target<matrix[i][j]) return search1(matrix,target,left,mid-1);
        else return search1(matrix,target,mid+1,right);
    }
    bool search(vector<int>& row, int target, int left, int right){
        if(left>right) return false;
        int mid=(left+right)/2;
        if(row[mid]==target) return true;
        else if(row[mid]<target) return search(row,target,mid+1,right);
        else return search(row,target,left,mid-1);
    }
    bool search(vector<vector<int>>& matrix, int target, int top, int bottom){
        if(top>bottom) return false;
        int mid=(top+bottom)/2;
        if(target>=matrix[mid][0] && target<=matrix[mid][matrix[mid].size()-1])
            return search(matrix[mid],target,0,matrix[mid].size()-1);
        else if(target<matrix[mid][0]) return search(matrix,target,top,mid-1);
        else return search(matrix,target,mid+1,bottom);
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//return search(matrix,target,0,matrix.size()*matrix[0].size()-1); // binary search on linear array(matrix can be stretched out into a single sorted array)
        return search(matrix,target,0,matrix.size()-1); // binary search on 2D matrix
    }
};