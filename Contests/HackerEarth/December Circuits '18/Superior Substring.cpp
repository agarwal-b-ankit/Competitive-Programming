#include <bits/stdc++.h>
using namespace std;
// uncomment for using ordered set provided by GNU++ library
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define mod 1000000007
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;

ll solve(string s){
    ll ans=3,i,j,k;
    vector<ll> fr[26];
    for(i=0;i<s.size();i++) fr[s[i]-'a'].pb(i);
    for(i=0;i<26;i++){
        if(fr[i].size()<=1) continue;
        for(j=1;j<fr[i].size();j++){
            for(k=j-ans/2;k>=0;k--){
                if(2*(j-k+1)+1>=(fr[i][j]-fr[i][k]+1))
                    ans=max(ans,2*(j-k+1)+1);
            }
        }
    }
    return min(ans,(ll)s.size());
}

int main()
{
	//FastIO
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string s;
		cin>>s;
		cout<<solve(s)<<"\n";
	}
	return 0;
}
