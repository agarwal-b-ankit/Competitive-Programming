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
	ll t,n;
	cin>>t;
	while(t--)
    {
        cin>>n;
        if(n%8==0)
            cout<<n-1<<"SL";
        else if(n%8==7)
            cout<<n+1<<"SU";
        else if(n%8==1)
            cout<<n+3<<"LB";
        else if(n%8==2)
        cout<<n+3<<"MB";
        else if(n%8==3)
            cout<<n+3<<"UB";
        else if(n%8==4)
            cout<<n-3<<"LB";
        else if(n%8==5)
            cout<<n-3<<"MB";
        else if(n%8==6)
            cout<<n-3<<"UB";
        cout<<endl;
    }
	return 0;
}
