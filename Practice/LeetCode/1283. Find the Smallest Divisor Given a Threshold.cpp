class Solution {
private:
    int findSum(vector<int>& num, int divisor){
        int sum=0;
        for(auto n:num){
            sum+=n/divisor;
            if(n%divisor!=0) sum+=1;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1,right=1e6;
        while(left<right){
            int mid=(left+right)/2;
            int sum = findSum(nums,mid);
            if(sum<=threshold){
                right=mid;
            } else{
                left=mid+1;
            }
        }
        return right;
    }
};