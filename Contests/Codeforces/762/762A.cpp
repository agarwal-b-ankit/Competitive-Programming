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

int main()
{
	ll n,k,i,pos=1;
	cin>>n>>k;
	ll div[(int)sqrt(n)+20];
	for(i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            div[pos++]=i;
        }
        if(pos-1==k)
            break;
    }
    if(pos-1==k)
        cout<<div[k];
    else
    {
        double sq=sqrt(n);
        if(sq==floor(sq))
        {
            if(k>2*pos-3)
                cout<<"-1";
            else cout<<n/div[2*pos-2-k];
        }
        else
        {
            if(k>2*pos-2)
                cout<<"-1";
            else cout<<n/div[2*pos-1-k];
        }
    }
	return 0;
}
