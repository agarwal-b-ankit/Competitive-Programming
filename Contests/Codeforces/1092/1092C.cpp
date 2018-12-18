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

vector<pair<string,ll> > st[101];
string ps[202];

bool solve(ll i, string pre, string suf){
    if(i==0) return true;
    pair<string,ll> p1,p2;
    p1=st[i][0],p2=st[i][1];
    if(pre.compare(p1.ff)==0 && suf.compare(p2.ff)==0){
        ps[p1.ss]="P";
        ps[p2.ss]="S";
    } else if(pre.compare(p2.ff)==0 && suf.compare(p1.ff)==0){
        ps[p1.ss]="S";
        ps[p2.ss]="P";
    } else return false;
    return solve(i-1, pre.substr(0,pre.length()-1), suf.substr(1));
}

int main()
{
	//FastIO
	ll t,n,i;
	cin>>n;
	string s;
	for(i=0;i<2*n-2;i++){
        cin>>s;
        st[s.length()].pb({s,i});
	}
	i=n-1;
    pair<string,ll> p1,p2;
    p1=st[i][0],p2=st[i][1];
    if(!solve(n-1,p1.ff,p2.ff)){
        solve(n-1,p2.ff,p1.ff);
    }
    for(i=0;i<2*n-2;i++) cout<<ps[i];
	return 0;
}
