class Solution {
public:
    int divide(int dividend, int divisor) {
        int neg=1;
        if(dividend<0 && divisor>0 || dividend>0 && divisor<0){
            neg=-1;
        }
        dividend=abs(dividend);
        divisor=abs(divisor);
        long left = 0, right = dividend,ans=0;
        while(left<=right){
           long mid = (left+right)/2;
            if(divisor*mid==dividend){
                ans=mid;
                break;
            }
            else if(divisor*mid<dividend){
                ans=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
       }
        ans=ans*neg;
        if(ans<INT_MIN) return INT_MIN;
        else if(ans>INT_MAX) return INT_MAX;
        else return ans;
    }
};