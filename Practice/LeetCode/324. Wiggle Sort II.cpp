class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int val[5001];
        for(int i=0;i<5001;i++)
            val[i]=0;
        for(int num:nums)
            val[num]++;
        int i=0,j=0,pos;
        vector<int> temp(nums.size());
        for(j=0;j<5001;j++)
            while(val[j]--)
                temp[i++]=j;
        
        for(i=1,j=nums.size()-1;i<nums.size();i+=2,j--)
            nums[i]=temp[j];
        for(i=0;i<nums.size();i+=2,j--)
            nums[i]= temp[j];
    }
};