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

vector<pair<ll,ll>> solve(string s){
    ll i,cnt=1;
    vector<pair<ll,ll>> v;
    for(i=1;i<s.size();i++){
	    if(s[i]!=s[i-1]){
	        v.pb({s[i-1],cnt});
	        cnt=1;
	    }
	    else cnt++;
	}
	v.pb({s[i-1],cnt});
	return v;
}

ll cal(vector<pair<ll,ll>> &a, vector<pair<ll,ll>> &b){
    if(a.size()!=b.size()) return -1;
    ll i,ans=0;
    for(i=0;i<a.size();i++)
        if(a[i].ff!=b[i].ff) return -1;
        else ans+=abs(b[i].ss-a[i].ss);
    return ans;
}

int main()
{
	//FastIO
	ll ans;
	string s1,s2;
	cin>>s1>>s2;
	vector<pair<ll,ll>> a=solve(s1),b=solve(s2);
	ans=cal(a,b);
    if(ans==-1) cout<<"Not possible";
    else cout<<ans;
	return 0;
}
