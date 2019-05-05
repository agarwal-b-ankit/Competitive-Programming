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
const ll MAXN=1000010;
 
vector<vector<ll>> v(MAXN);
string st[1010];
vector<ll> val(MAXN,-1);
vector<bool> vis(MAXN,false);
ll ans=0;
 
void dfs(ll src){
    ans=max(ans,val[src]);
    vis[src]=true;
    for(auto e:v[src]){
        if(!vis[e] && val[e]>0)
            dfs(e);
    }
}
 
void bfs(){
    queue<ll> q;
    q.push(0);
    ll depth=-1;
	while(!q.empty()){
	    ll siz=q.size();
	    while(siz--){
    	    ll p = q.front();q.pop();
    	    for(auto e:v[p]){
    	        if(val[e]==-1){
    	            q.push(e);
    	            val[e]=depth+1;
    	        }
    	    }
	    }
	    depth++;
	}
}
 
int main()
{
	//FastIO
	ll n,m,a,b,k,x,y,i,j;
	char ch;
	cin>>n>>m>>a>>b>>ch;
	for(i=0;i<n+1;i++) getline(cin,st[i]);
	cin>>k;
	for(i=1;i<=n;i++){
	    for(j=1;j<=2*m;j++){
	        if(j%2==1 && st[i][j]!='_'){
	            ll ind=(i-1)*m+(j+1)/2;
	            v[ind].pb(ind+m);
	            v[ind+m].pb(ind);
	        }
	        else if(j%2==0 && st[i][j]!='|'){
	            ll ind=(i-1)*m+j/2;
	            v[ind].pb(ind+1);
	            v[ind+1].pb(ind);
	        }
	    }
	}
	for(i=0;i<k;i++){
	    cin>>x>>y;
	    v[0].pb((x-1)*m+y);
	}
	bfs();
	dfs((a-1)*m+b);
	cout<<ans;
	return 0;
}