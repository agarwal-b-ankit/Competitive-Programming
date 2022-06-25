class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ng(nums.size(),-1);
        int n=nums.size();
        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                ng[st.top()]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return ng;
    }
};