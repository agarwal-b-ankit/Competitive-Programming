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

ll a[MAXN],b[MAXN];

void solve(string s){
    ll i,l=0,r=0;
    for(i=0;i<s.size();i++)
        if(s[i]=='(') l++;
        else if(l>0) l--;
        else{
            l=-1;
            break;
        }
    if(l>=0){
        a[l]++;
        return;
    }
    for(i=s.size()-1;i>=0;i--)
        if(s[i]==')') r++;
        else if(r>0) r--;
        else{
            r=-1;
            break;
        }
    if(r>=0) b[r]++;
}

int main()
{
	//FastIO
	ll t,n,i,ans=0;
	cin>>n;
	string s;
	for(i=0;i<n;i++){
        cin>>s;
        solve(s);
	}
	ans=a[0]/2;
	for(i=1;i<MAXN;i++) ans+=min(a[i],b[i]);
	cout<<ans;
	return 0;
}
