class Solution {
public:
    bool isPalindrome(int x) {
        long original=x,y=0;
        while(x>0){
            y=y*10+x%10;
            x/=10;
        }
        return original==y;
    }
};