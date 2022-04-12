class Solution {
public:
    vector<int> combine(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        for(int num1:nums1)
            for(int num2:nums2)
                res.push_back(num1+num2);
        return res;
    }
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        vector<int> arr1 = combine(nums1, nums2);
        vector<int> arr2 = combine(nums3, nums4);
        map<int,int> m;
        for(int num:arr1)
            m[num]++;
        int ans = 0;
        for(int num:arr2){
            if(m.find(-num)!=m.end())
                ans+=m[-num];
        }
        return ans;
    }
};