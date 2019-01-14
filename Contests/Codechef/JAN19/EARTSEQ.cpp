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

bool prime[MAXN];
vector<ll> primes;

void sieve(ll n){
    ll i,j;
    for(i=2;i<=n;i++) prime[i]=true;
    for(i=2;i*i<=n;i++){
        if(prime[i]){
            for(j=i*i;j<=n;j+=i)
                prime[j]=false;
        }
    }
    for(i=2;i<=n;i++)
        if(prime[i])
            primes.pb(i);
}

int main()
{
	FastIO
	sieve(MAXN);
	ll t,n,i=0,j=1,step=4,flag=0;
	vector<ll> ans;
	while(ans.size()<50001){
        if(primes[i]*primes[j]>1e9){
            if(flag) ans.pb(primes[i]*primes[0]);
            else ans.pb(primes[j]*primes[0]);
            i=0;j=step;
            step+=2;
            flag=1;
            continue;
        }
        ans.pb(primes[i]*primes[j]);
        if(flag) i++;
        else j++;
        flag=1-flag;
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==4) cout<<"6 10 35 21";
		else if(n==5) cout<<"6 10 55 77 21";
		else if(n==6) cout<<"6 10 55 77 91 39";
        else if(n==8) cout<<"6 10 55 77 91 143 187 51";
		else
        for(i=0;i<n;i++){
            if(i==n-1)
                cout<<__gcd(ans[i],ans[i-1])*3<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
