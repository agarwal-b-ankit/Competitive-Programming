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

ll a[MAXN],b[MAXN];

int main()
{
	//FastIO
	ll n,i,len,ans=0;
	cin>>n;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
        a[i]=b[i]=-1;
	for(i=0,len=0;i<n;i++){
        if(s[i]=='(')
            a[i]=++len;
        else if(len>0)a[i]=--len;
        else break;
	}
	for(i=n-1,len=0;i>=0;i--){
       if(s[i]==')')
            b[i]=++len;
        else if(len>0)b[i]=--len;
        else break;
	}
    for(i=0;i<n;i++){
        ll left=0,right=0;
        if((i>0 && a[i-1]==-1) || (i<n-1 && b[i+1]==-1)) continue;
        if(i>0) left=a[i-1];
        if(i<n-1) right=b[i+1];
        if(s[i]=='(' && left==right+1) ans++;
        else if(s[i]==')' && left+1==right) ans++;
    }
    cout<<ans;
	return 0;
}
