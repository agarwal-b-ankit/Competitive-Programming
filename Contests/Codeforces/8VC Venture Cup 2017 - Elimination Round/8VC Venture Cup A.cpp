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
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)

bool isPrime(ll n)
{
    for(ll i=2;i<=(ll)sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
	ll n;
	cin>>n;
    for(ll i=1;i<=1000;i++)
    {
        if(!isPrime(n*i+1LL))
        {
            cout<<i;
            break;
        }
    }
	return 0;
}
