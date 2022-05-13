class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mini(nums.size(),0);
        stack<int> st;
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            mini[i]=min(mini[i-1],nums[i]);
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]==mini[i]) continue;
            while(!st.empty() && st.top()<=mini[i])
                st.pop();
            if(!st.empty() && nums[i]>st.top()) return true;
            st.push(nums[i]);
        }
        return false;
    }
};