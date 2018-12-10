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
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

ll n,n1;
ll dp[60][2][2][2][2];

ll solve(ll pos, ll low1, ll low2, ll carry, ll zero){
    if(pos==-1){
        if(low2==1 && carry==0 && zero==1){
            return 1;
        }
        else return 0;
    }
    if(dp[pos][low1][low2][carry][zero]!=-1) return dp[pos][low1][low2][carry][zero];
    ll i,j,c,dig=0,dig1=0,ans=0,lpos=(1LL)<<pos;
    if(n & lpos) dig=1;
    if(n1 & lpos) dig1=1;
    for(i=0;i<2;i++){
        if(!low1 && i>dig) break;
        for(j=0;j<2;j++){
            if(!low2 && j>i) break;
                for(c=0;c<2;c++){
                    if((i^j^((i+j+c)%2))==dig1 && ((carry==1 && i+j+c>1) || (carry==0 && i+j+c<2))){
                    ans+=solve(pos-1,(low1 | (i<dig)),(low2 | (j<i)), c,(zero | j));
                    ans%=mod;
                }
            }
        }
    }
    ans%=mod;
    return dp[pos][low1][low2][carry][zero]=ans;
}

int main()
{
	//FastIO
	ll t,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%4==0) n1=n;
		else if(n%4==1) n1=1;
        else if(n%4==2) n1=n+1;
        else n1=0;
        memset(dp,-1,sizeof(dp));
        ll ans=solve((ll)log2(n),0,0,0,0);
        if((ll)log2(n1)>(ll)log2(n))
            ans+=solve((ll)log2(n),0,0,1,0);
        cout<<ans%mod<<"\n";
	}
	return 0;
}
