#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

int main()
{
	ll n,a,b,c=INF,c1=-INF,flag=0,imp=0;
	cin>>n;
	for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b==2 && flag==0)
            flag=1;
        if(b==2 && c>=1900)
            c=1899;
        else if(b==1 && c1<1900)
            c1=1900;

        if(c<c1)
            imp=1;
        c+=a;
        c1+=a;
        cout<<c<<endl;
    }
    if(flag==0)
        cout<<"Infinity";
    else if(imp==1)
        cout<<"Impossible";
    else
        cout<<c;
	return 0;
}
