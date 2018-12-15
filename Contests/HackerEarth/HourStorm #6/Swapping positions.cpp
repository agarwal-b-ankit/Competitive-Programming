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

string s,t;

bool check1(ll i, ll j){
    if(s[i]==t[j] || s[j]==t[i]) return true;
    if(s[i]==s[j] || t[j]==t[i]) return true;
    return false;
}

bool check2(ll i, ll j){
    if(s[i]==t[j] && s[j]==t[i]) return true;
    if(s[i]==s[j] && t[j]==t[i]) return true;
    return false;
}

int main()
{
	//FastIO
	ll t1,n,i;
	cin>>t1;
	while(t1--)
	{
		cin>>n>>s>>t;
		vector<ll> v;
		for(i=0;i<s.size();i++){
            if(s[i]!=t[i]) v.pb(i);
		}
		bool flag=false;
		if(v.size()<2) flag=true;
		if(v.size()==2 && check1(v[0],v[1])) flag=true;
		if(v.size()==3 && (check2(v[0],v[1]) || check2(v[1],v[2]) || check2(v[0],v[2]))) flag=true;
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
