#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

ll n,k;
ll Fen[lim]={0};

void update(ll ind, ll val)
{
    for(ll j=ind;j<=n;j+=(j&(-j)))
        Fen[j]+=val;
}

ll Sum(ll ind)
{
    ll ans=0;
    for(ll j=ind;j>0;j-=(j&(-j)))
        ans+=Fen[j];
    return ans;
}

ll solve(ll a, ll b)
{
    if(b>a)
        return Sum(b-1)-Sum(a);
    else return Sum(n)-Sum(a)+Sum(b-1);
}

int main()
{
    ll cur=1,next,ans=1;
	cin>>n>>k;
	k=min(k,n-k);
    for(ll i=0;i<n;i++)
    {
        next=(cur+k-1)%n+1;
        ans+=solve(cur,next)+1;
        update(cur,1);
        update(next,1);
        cur=next;
        cout<<ans<<" ";
    }
	return 0;
}
