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
	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	string st;
	while(getline(cin,st)){
	    ll i,ind,siz,cind=-1;
        vector<vector<ll> > v(26);
        vector<ll> pos(26,-1);
        set<char> ch;
        set<ll> li;
        for(i=0;i<st.size();i++){
            v[st[i]-'a'].pb(i);
            pos[st[i]-'a']=i;
            ch.insert(st[i]);
        }
        siz=ch.size();
        for(char c:ch) li.insert(pos[c-'a']);
        while(siz--){
            for(char c:ch){
                ind=upper_bound(all(v[c-'a']),cind)-v[c-'a'].begin();
                ind=v[c-'a'][ind];
                if(li.lower_bound(ind)==li.begin()){
                    printf("%ch",c);
                    li.erase(pos[c-'a']);
                    ch.erase(c);
                    cind=ind;
                    break;
                }
            }
        }
        cout<<"\n";
	}
	return 0;
}
