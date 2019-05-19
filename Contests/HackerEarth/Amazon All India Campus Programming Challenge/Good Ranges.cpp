#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,q,x,i,ans=0;
    cin>>n>>q;
    set<ll> s;
    vector<ll> cnt(n+1,0);
    map<ll,pair<ll,ll>> m;
    while(q--){
        cin>>x;
        if(s.empty()){
            m[x]={1,n};
            ans+=(m[x].first+m[x].second);
        } else{
            auto it = s.lower_bound(x);
            if(it==s.end()){
                it--;
                ll val=*it;
                ans-=m[val].second;
                m[val].second=x-1;
                ans+=m[val].second;
                m[x]={val+1,n};
                ans+=(m[x].first+m[x].second);
            } else if(*it==x){
                // do nothing
            } else{
                ll val=*it;
                ans-=m[val].first;
                m[val].first=x+1;
                ans+=m[val].first;
                if(it!=s.begin()){
                    m[x]={1,val-1};
                    val=*(--it);
                    m[x].first=val+1;
                    ans+=(m[x].first+m[x].second);
                    ans-=m[val].second;
                    m[val].second=x-1;
                    ans+=m[val].second;
                } else{
                    m[x]={1,val-1};
                    ans+=(m[x].first+m[x].second);
                }
            }
        }
        s.insert(x);
        cnt[x]++;
        cout<<ans<<"\n";
    }
    return 0;
}