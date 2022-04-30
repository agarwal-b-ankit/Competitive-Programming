class Solution {
public:    
    int trap(vector<int>& height) {
        int water = 0;
        stack<int> st;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int mid = st.top();
                st.pop();
                if(st.empty()) break;
                int left = st.top();
                int waterHeight = min(height[left],height[i])-height[mid];
                water+=waterHeight*(i-left-1);
            }
            st.push(i);
        }
        return water;
    }
};