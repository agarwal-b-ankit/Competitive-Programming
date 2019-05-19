#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll c[1000010],ans;
 
void solve(ll n){
    ans=max(ans,c[n]);
    if(n>1)
        solve(n/2);
}
 
int main(){
    ll n,q,t,v,col=0;
    cin>>n>>q;
    while(q--){
        cin>>t>>v;
        if(t==1){
            ans=0;
            solve(v);
            cout<<ans<<"\n";
        } else
            c[v]=++col;
    }
    return 0;
}