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
	ll n,x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>n;
	while(n--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        if(x1==x2 && x3==x4 && x2==x3)
        {
            if( min(y1,y2)>max(y3,y4) || max(y1,y2)<min(y3,y4))
                cout<<"no";
            else cout<<"yes";
        }
        else if(y1==y2 && y3==y4 && y2==y3)
        {
            if( min(x1,x2)>max(x3,x4) || max(x1,x2)<min(x3,x4))
                cout<<"no";
            else cout<<"yes";
        }
        else if( (x1==x2 && y3==y4 && (y3==y2 || y3==y1) && (min(x3,x4)==x1 || max(x3,x4)==x1 )) || (x3==x4 && y1==y2 && (y2==y3 || y2==y4) && (min(x1,x2)==x3 || max(x1,x2)==x3)) )
            cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
	return 0;
}
