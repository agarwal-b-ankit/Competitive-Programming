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
#define lld long long
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

ll di[4010][4010],n;

void cal(vector<vector<ll> > &v, ll s, ll d, ll i, vector<ll> &vis){
    di[i][s]=d;
    vis[s]=true;
    for(ll ind:v[s]){
        if(!vis[ind])
            cal(v,ind,d+1,i,vis);
    }
}

void dfs(vector<vector<ll> > &v, ll i){
    vector<ll> vis(n+1,false);
    cal(v,i,0,i,vis);
}

int main()
{
	//FastIO
	ll q,i,j,u,v,p;
	cin>>n;
	vector<vector<ll> > g(n+1);
	for(i=0;i<n-1;i++){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
	}
	for(i=1;i<=n;i++){
        dfs(g,i);
	}
	vector<ll> temp;
	for(j=0;j<n;j++){
        ll ans,sumans=INF;
        cin>>p;
        temp.pb(p);
        if(j==0) ans=p;
        else{
            for(i=1;i<=n;i++){
                ll sum=0;
                for(ll each:temp){
                    sum=max(di[i][each],sum);
                }
                if(i==1 || sum<sumans){
                    ans=i;
                    sumans=sum;
                }
            }
        }
        cout<<ans<<" ";
	}
	return 0;
}
