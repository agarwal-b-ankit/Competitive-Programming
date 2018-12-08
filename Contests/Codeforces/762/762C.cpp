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
	ll n,i,st,en,pos=0,len=-1;
	string a,b;
	cin>>a>>b;
	ll pre[a.size()],suf[a.size()];
	for(i=0;i<a.size();i++)
    {
        if(a[i]==b[pos])
            pos++;
        pre[i]=pos;
    }
    pos=0;
    for(i=a.size()-1;i>=0;i--)
    {
        if(a[i]==b[b.size()-1-pos])
            pos++;
        suf[i]=pos;
    }
    for(i=0;i<a.size()-1;i++)
    {
        if(pre[i]+suf[i+1]>len)
        {
            len=pre[i]+suf[i+1];
            st=pre[i];
            en=suf[i+1];
            if(len>b.size())
                break;
        }
    }
    if(suf[0]>len)
    {
        len=suf[0];
        st=0;
        en=suf[0];
    }
    if(pre[a.size()-1]>len)
    {
        len=pre[a.size()-1];
        st=len;
        en=0;
    }
    if(len>b.size())
        cout<<b;
    else if(len==0)
        cout<<"-";
    else
    cout<<b.substr(0,st)+b.substr(b.size()-en,en);
	return 0;
}
