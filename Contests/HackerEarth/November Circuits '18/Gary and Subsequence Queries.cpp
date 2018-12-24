#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
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

vector<ll> v[100001][26];
string str[100001];
map<pair<ll,ll>,bool> m;

int main()
{
	FastIO
	ll n,q,x,y,i,j,pind,cind;
	cin>>n>>q;
	string st;
	for(i=1;i<=n;i++){
	    cin>>str[i];
	    for(j=0;j<(ll)str[i].size();j++){
	        v[i][str[i][j]-'a'].pb(j);
	    }
	}
	while(q--){
	    cin>>x>>y;
	    if(x==y){
            printf("Yes\n");
            continue;
	    }
	    // take x as shortest string, in case of equality take lower index one as x
	    if(str[x].size()>str[y].size() || (str[x].size()==str[y].size() && x>y) ){
	        x=x^y;
	        y=x^y;
	        x=x^y;
	    }
	    pair<ll,ll> key = mp(x,y);
	    if(!present(m,key)){
            bool flag=true;
            if(str[x].size()==str[y].size()){
                if(str[x].compare(str[y])!=0) flag=false;
            } else{
                pind=-1;
                for(char c:str[x]){
                    if(v[y][c-'a'].empty()){
                        flag=false;
                        break;
                    }
                    cind=upper_bound(all(v[y][c-'a']),pind)-v[y][c-'a'].begin();
                    if(cind==(ll)v[y][c-'a'].size()){
                        flag=false;
                        break;
                    }
                    pind=v[y][c-'a'][cind];
                }
            }
            m.insert(mp(key,flag));
	    }
        if(m[key])
        cout<<"Yes\n";
        else cout<<"No\n";
	}
	return 0;
}
