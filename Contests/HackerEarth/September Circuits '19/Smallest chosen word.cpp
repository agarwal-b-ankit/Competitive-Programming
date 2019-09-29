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
 
vector<ll> fre[26];
 
int main()
{
	//FastIO
	ll i,j,l1,l2,l3,minl=-1;
	cin>>l1>>l2>>l3;
	string s1,s2,s3;
	string s="";
	cin>>s1>>s2>>s3;
	for(i=0;i<s2.size();i++)
	    fre[s2[i]-'a'].pb(i);
	ll pos=(s3[0]-'a');
	bool flag=false;
	for(i=1;i<s3.size();i++){
	    if(s3[i]==s3[i-1]) continue;
	    if(s3[i]>s3[i-1]) flag=true;
	    break;
	}
	if(!flag)
	    pos--;
	for(i=0;i<=pos;i++){
	    for(j=0;j<fre[i].size();j++){
	        if(fre[i][j]>minl){
	            s+=('a'+i);
	            minl=fre[i][j];
	        }
	    }
	}
	cout<<s1<<s<<s3;
	return 0;
}
