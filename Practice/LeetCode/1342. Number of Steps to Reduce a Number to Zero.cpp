class Solution {
public:
    int numberOfSteps(int num) {
        int step=0;
        while(num>0){
            step+=num%2;
            num/=2;
            if(num==0) break;
            step++;
        }
        return step;
    }
};