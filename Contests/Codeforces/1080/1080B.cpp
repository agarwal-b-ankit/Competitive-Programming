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
	ll q,n,l,r,ft1,ft2,nt1,nt2;
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		if(l==r){
            if(l%2==0)
            cout<<l; else cout<<-l;
            cout<<endl;
            continue;
		}
        nt1=(r-l+1)/2+(r-l+1)%2;
        nt2=(r-l+1)/2;
        if(l%2==0){
            ft1=l,ft2=-(l+1);
            ll sum1=nt1*ft1+(nt1)*(nt1-1);
            ll sum2=nt2*ft2-(nt2)*(nt2-1);
            cout<<sum1+sum2;
        } else {
            ft1=-l,ft2=l+1;
            ll sum1=nt1*ft1-(nt1)*(nt1-1);
            ll sum2=nt2*ft2+(nt2)*(nt2-1);
            cout<<sum1+sum2;
        }
        cout<<endl;
	}
	return 0;
}
