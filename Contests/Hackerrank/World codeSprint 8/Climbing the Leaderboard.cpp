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
	ll n,i,m,val,pos;
	cin>>n;
	map<ll,ll> ma;
	vector<ll> v;
	for(i=0;i<n;i++)
    {
        cin>>val;
        ma[val]++;
        if(ma[val]==1)
            v.pb(val);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>val;
        pos=1+v.size()-(upper_bound(v.begin(),v.end(),val)-v.begin());
        cout<<pos<<endl;
    }
	return 0;
}
