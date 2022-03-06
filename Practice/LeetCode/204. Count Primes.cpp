class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> prime(n,1);
        for(int i =2;i<n;i++){
            if(prime[i]){
                ans++;
                for(int j=i*2;j<n;j+=i)
                    prime[j]=0;
            }
        }
        
        return ans;
    }
};