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
const ll MAXN=500010;

ll par[MAXN];
bool mark[MAXN],exclude[MAXN];

ll fin(ll x){
    if(par[x]!=x)
        par[x]=fin(par[x]);
    return par[x];
}

ll uni(ll x, ll y){
    ll py=fin(y);
    if(py==x)
        mark[x]=true;
    else par[x]=py;
}

int main()
{
	//FastIO
	ll n,q,i,type,x;
	cin>>n;
	vector<ll> v(n+1),ans;
	vector<pair<ll,ll>> vq;
	for(i=1;i<=n;i++){
	    cin>>v[i];
	    par[i]=i;
	}
	cin>>q;
	for(i=1;i<=q;i++){
	    cin>>type>>x;
	    if(type==2) exclude[x]=true;
	    vq.pb({type,x});
	}
	for(i=1;i<=n;i++)
	    if(v[i]!=0 && !exclude[i])
	        uni(i,v[i]);
	reverse(all(vq));
	for(auto p:vq){
	    if(p.ff==1){
	        ll parent=fin(p.ss);
	        if(mark[parent]) ans.pb(-1);
	        else ans.pb(parent);
	    }
	    else uni(p.ss,v[p.ss]);
	}
	reverse(all(ans));
	for(auto e:ans)
	    if(e!=-1) cout<<e<<"\n";
	    else cout<<"LOOP\n";
	return 0;
}
