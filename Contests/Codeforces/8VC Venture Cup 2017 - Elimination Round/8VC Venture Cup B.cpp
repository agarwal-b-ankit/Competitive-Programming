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

int main()
{
	ll n,m,dup=0,p1=0,p2=0;
	cin>>n>>m;
	ll n1=n,m1=m;
	string s;
	map<string,ll> ma;
	while(n--)
    {
        cin>>s;
        ma[s]++;
    }
    while(m--)
    {
        cin>>s;
        ma[s]++;
        if(ma[s]==2)
            dup++;
    }
    p1=n1-dup+dup/2+dup%2;
    p2=m1-dup+dup/2;
    if(p1>p2)
        cout<<"YES";
    else cout<<"NO";
	return 0;
}
