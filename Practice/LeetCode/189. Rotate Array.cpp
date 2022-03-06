class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || k==0 || k%nums.size()==0) return;
        int num = gcd(min((int)nums.size(),k), max((int)nums.size(),k));
        for(int i=0;i<num;i++){
            int j = i, prev = nums[i], temp;
            do{
                j = ((j+k)%nums.size());
                temp = nums[j];
                nums[j] = prev;
                prev = temp;
            } while(j!=i);
        }
    }
};