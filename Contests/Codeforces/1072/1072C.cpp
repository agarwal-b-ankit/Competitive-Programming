#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	ll a,b,i,cnt,temp;
	cin>>a>>b;
	vector<ll> va,vb;
	ll val=0;
	while((val+1)*(val+2)<=2*(a+b)) val++;
    for(i=val;i>=1;i--){
        if(i<=a){
            a-=i;
            va.pb(i);
        }else vb.pb(i);
    }
    cout<<va.size()<<endl;
    for(i=0;i<va.size();i++)
        cout<<va[i]<<" ";
    cout<<endl;
    cout<<vb.size()<<endl;
    for(i=0;i<vb.size();i++)
        cout<<vb[i]<<" ";
	return 0;
}
