#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

queue<ll> q;
unordered_map<ll,vector<ll> > invertex;
unordered_map<ll,ll> outcnt;

void process(ll p){
    for(auto val:invertex[p]){
        outcnt[val]--;
        if(outcnt[val]==0) q.push(val);
    }
}

void solve(){
    ll n,m,i,u,v;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        outcnt[i]=0;
    }
    for(i=0;i<m;i++){
        cin>>u>>v;
        outcnt[u]++;
        invertex[v].pb(u);
    }
    for(i=1;i<=n;i++){
        if(outcnt[i]==0) q.push(i);
    }
    vector<vector<ll>> ans;
    while(!q.empty()){
        ll p = q.front();
        q.pop();
        if(!q.empty()){
            ll p2 = q.front();
            q.pop();
            vector<ll> temp={2,p,p2};
            process(p);
            process(p2);
            ans.pb(temp);
        } else{
            vector<ll> temp={1,p};
            process(p);
            ans.pb(temp);
        }
    }
    cout<<ans.size()<<endl;
    for(auto ve:ans){
        for(auto val:ve) cout<<val<<" ";
        cout<<"\n";
    }
}

int main()
{
	FastIO
	solve();
	return 0;
}
