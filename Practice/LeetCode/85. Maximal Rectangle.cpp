class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(),-1), right(heights.size(),heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    temp[i][j]=1;
                    if(i>0)
                        temp[i][j]+=temp[i-1][j];
                }
            }
            ans=max(ans,largestRectangleArea(temp[i]));
        }
        return ans;
    }
};