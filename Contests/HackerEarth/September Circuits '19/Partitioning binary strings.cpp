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
const ll MAXN=5001;
 
/*struct custom_hash { 
    template <class T> 
    size_t operator()(const pair<T, pair<T,T>>& p) const
    { 
        auto hash1 = hash<T>{}(p.first); 
        auto hash2 = hash<T>{}(p.second.first);
        auto hash3 = hash<T>{}(p.second.second);
        return (hash1 ^ hash2) ^ hash3; 
    } 
};
 
unordered_map<pair<int,pair<int,int>>,int, custom_hash> m;
*/
int dp[MAXN][MAXN/2][5];
int n,pos;
int b[MAXN];
string s;
 
ll solve(ll ind, ll minl, ll minv){
    //pair<int,pair<int,int>> p={ind,{minl,minv}};
    //if(s[ind]=='0') return 0;
    if(ind==pos) return 1;
    //if(present(m,p)) return m[p];
    if(dp[ind][minl][minv]!=-1) return dp[ind][minl][minv];
    ll ans=0,n1=0,len=0;
    for(ll i=ind+1;i<=pos;i++){
        //cnt=(s[i]-'0');
        //len++;
        n1=n1+1;
        len=b[i]-b[ind];
        if(n1<minv || len<minl) continue;
        ans+=solve(i,len,n1);
        if(ans>=mod) ans=ans-mod;
    }
    //return m[p]=ans;
    return dp[ind][minl][minv]=ans;
}
 
int main()
{
	//FastIO
	cin>>n>>s;
	for(ll i=0;i<MAXN;i++)
	    for(ll j=0;j<MAXN/2;j++)
	        for(ll k=0;k<5;k++)
	            dp[i][j][k]=-1;
	pos=0;
	for(ll i=0;i<n;i++){
	    if(s[i]=='1')
	        b[pos++]=i;
	}
	b[pos]=n;
	cout<<solve(0,0,0);
	return 0;
}