#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll p[40];
 
ll pre(){
    p[0]=1;
    for(ll i=1;i<40;i++)
        p[i]=p[i-1]*3;
}
 
ll solve(ll n){
    if(n==0) return 0;
    for(ll i=1;i<40;i++){
        if(p[i]>n)
            return i-1+solve(n-p[i-1]);
    }
}
 
int main(){
    ll t,n,u,v;
    cin>>t;
    pre();
    while(t--){
        cin>>n>>u>>v;
        ll diff=abs(v-u);
        if(diff%3!=0) cout<<"-1\n";
        else cout<<solve(diff)<<"\n";
    }
    return 0;
}