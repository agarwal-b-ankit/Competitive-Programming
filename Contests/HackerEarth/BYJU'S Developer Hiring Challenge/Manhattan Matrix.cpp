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
#define mod 1000000007
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;
 
int main()
{
	//FastIO
	ll t,n,m,i,j,query;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    vector<vector<ll>> v(n,vector<ll>(m));
	    vector<vector<ll>> graph(n*m);
	    vector<ll> dist(n*m,-1);
	    vector<ll> vis(n*m,false);
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>v[i][j];
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            for(ll x=max(0ll,i-v[i][j]);x<=min(n-1,i+v[i][j]);x++){
	                for(ll y=max(0ll,j-v[i][j]);y<=min(m-1,j+v[i][j]);y++){
	                    if(abs(x-i)+abs(y-j)==v[i][j])
	                        graph[i*m+j].pb(x*m+y);
	                }
	            }
	        }
	    }
	    ll sx,sy;
	    cin>>sx>>sy;
	    sx--;sy--;
	    queue<ll> q;
	    q.push(sx*m+sy);
	    vis[sx*m+sy]=true;
	    ll ans=0;
	    while(!q.empty()){
	        ll siz=q.size();
	            while(siz--){
	            ll val=q.front();
	            q.pop();
	            dist[val]=ans;
	            for(auto e: graph[val])
	                if(!vis[e]){
	                    vis[e]=true;
	                    q.push(e);
	                }
	        }
	        ans++;
	    }
	    cin>>query;
	    while(query--){
	        cin>>sx>>sy;
	        sx--;sy--;
	        cout<<dist[sx*m+sy]<<"\n";
	    }
	}
	return 0;
}