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
	ll t;
	cin>>t;
	while(t--)
    {
        ll n,i;
        cin>>n;
        map<ll,ll> m;
        map<ll,ll>::iterator it;
        vector<ll> temp;
        vector<vector<ll> > adj(n,temp);
        ll a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]=i;
        }
        for(i=0;i<n-1;i++)
        {
            ll v,u;
            cin>>v>>u;
            v--;
            u--;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        for(i=0;i<n;i++)
        {
            m.erase(a[i]);
            for(ll j:adj[i])
                m.erase(a[j]);
            it=m.end();
            it--;
            cout<<(it->second+1)<<" ";
            m[a[i]]=i;
            for(ll j:adj[i])
                m[a[j]]=j;
        }
        cout<<endl;
    }
	return 0;
}
