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
	ll s,val,n,i;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++){
            s=0;
        for(int j=0;j<5;j++){
            cin>>val;
            s+=val;
        }
    a[i]=s;
	}
	for(i=0;i<n;i++){
        if(a[i]==0)
            cout<<"Beginner"<<endl;
        else if(a[i]==1)
            cout<<"Junior Developer"<<endl;
        else if(a[i]==2)
            cout<<"Middle Developer"<<endl;
            else if(a[i]==3)
            cout<<"Senior Developer"<<endl;
            else if(a[i]==4)
            cout<<"Hacker"<<endl;
            else
            cout<<"Jeff Dean"<<endl;
	}
	return 0;
}
