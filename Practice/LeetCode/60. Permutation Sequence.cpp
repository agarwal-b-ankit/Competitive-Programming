class Solution {
private:
    int fact[10];
    void init(){
        fact[0]=fact[1]=1;
        for(int i=2;i<10;i++) fact[i]=fact[i-1]*i;
    }
public:
    string getPermutation(int n, int k) {
        init();
        string ans;
        vector<int> num(n);
        for(int i=0;i<n;i++) num[i]=i+1;
        k--;
        while(num.size()>0){
            ans+=to_string(num[k/fact[n-1]]);
            num.erase(num.begin()+k/fact[n-1]);
            k=k%fact[n-1];
            n--;
        }
        return ans;
    }
};