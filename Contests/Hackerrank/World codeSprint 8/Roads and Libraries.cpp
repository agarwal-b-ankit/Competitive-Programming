#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

struct ufind
{
    ll n;
    ll *parent,*ran;

    ufind(ll n)
    {
        this->n=n;
        parent=new ll[n];
        ran=new ll[n];
        for(ll i=0;i<n;i++)
        {
            parent[i]=i;
            ran[i]=0;
        }
    }

    ll fin(ll v)
    {
        if(parent[v]!=v)
            parent[v]=fin(parent[v]);
        return parent[v];
    }

    void uni(ll a, ll b)
    {
        ll p1=fin(a),p2=fin(b);
        if(p1==p2)
            return;
        if(ran[p1]>ran[p2])
            parent[p2]=p1;
        else parent[p1]=p2;
        if(ran[p1]==ran[p2])
            ran[p2]++;
    }

    ll distinct()
    {
        set<ll> s;
        for(ll i=0;i<n;i++)
            s.insert(fin(i));
        return s.size();
    }
};

int main()
{
	ll q;
	cin>>q;
	while(q--)
    {
        ll n,m,cl,cr,u,v,siz;
        cin>>n>>m>>cl>>cr;
        ufind uf(n);
        while(m--)
        {
            cin>>u>>v;
            u--;
            v--;
            uf.uni(u,v);
        }
        siz=uf.distinct();
        ll ans=min(cr*(n-siz)+siz*cl,n*cl);
        cout<<ans<<endl;
    }
	return 0;
}
