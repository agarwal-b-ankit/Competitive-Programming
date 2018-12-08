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
	ll n,c=0,k,t=5,b=0;
	cin>>n;
	cin>>k;
	while(c+t<=240-k)
    {
        c+=t;
        t+=5;
        b++;
        if(b==n)
            break;
    }
    cout<<b;
	return 0;
}
