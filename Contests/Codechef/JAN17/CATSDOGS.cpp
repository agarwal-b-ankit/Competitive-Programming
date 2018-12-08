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
	ll n;
	cin>>n;
	while(n--)
    {
        ll c,d,l;
        cin>>c>>d>>l;
        ll mi=d*4,ma=(c+d)*4;
        if(c>2*d)
            mi+=4*(c-2*d);
        if(l>=mi && l<=ma && l%4==0)
            cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
	return 0;
}
