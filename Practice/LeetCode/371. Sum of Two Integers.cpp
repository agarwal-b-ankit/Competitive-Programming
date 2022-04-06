class Solution {
public:
    uint32_t sum(uint32_t a, uint32_t b) {
        if(b==0) return a;
        return sum(a^b,(a&b)<<1);
    }
    
    int getSum(int a, int b) {
        return sum(a,b);
    }
};