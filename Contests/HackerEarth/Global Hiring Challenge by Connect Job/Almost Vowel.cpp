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

bool isVowel(char c){
    return c=='a' || c=='e' || c=='i'|| c=='o' || c=='u';
}

int main()
{
	//FastIO
	ll t,i,j;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		vector<ll> v;
		ll ans=0,mx=0,cnt=0,l=0,r=s.size()-1;
		for(l=0;l<s.size();l++)
		    if(!isVowel(s[l]))
		        break;
		ans+=l;
		for(r=s.size()-1;r>=l;r--)
		    if(!isVowel(s[r]))
		        break;
		ans+=(s.size()-1-r);
		for(i=l+1;i<r;i++){
		    if(isVowel(s[i])){
		        cnt++;
		        mx=max(mx,cnt);
		    } else cnt=0;
		}
		ans+=mx;
		cout<<ans<<"\n";
	}
	return 0;
}
