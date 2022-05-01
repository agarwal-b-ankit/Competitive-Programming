class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        
        string ans;
        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) ans+="-";
        long num=labs(numerator);
        long den=labs(denominator);
        long quotient = num/den;
        ans += to_string(quotient);
        if(num%den==0) return ans;
        
        ans+=".";
        long remainder = num%den;
        unordered_map<int,int> pos;
        while(remainder>0){
            if(pos.find(remainder)!=pos.end()){
                ans.insert(pos[remainder],"(");
                ans+=")";
                break;
            }
            pos[remainder]=ans.size();
            remainder*=10;
            quotient = remainder/den;
            remainder%=denominator;
            ans+=to_string(quotient);
        }
        return ans;
    }
};