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
const ll MAXN=2050;

ll dp[MAXN][35],pre[MAXN][MAXN],a[MAXN];

void preProcess(string s){
    ll i,j;
    for(i=0;i<s.size();i++)
	    a[i]=s[i]-'a';
    for(i=0;i<s.size();i++){
        ll temp[26];
        memset(temp,0,sizeof(temp));
	    for(j=i;j<s.size();j++){
	        ll st=INF;
	        for(ll v1=0;v1<26;v1++){
                if(a[j]>v1) temp[v1]+=26-a[j]+v1;
                else temp[v1]+=v1-a[j];
                st=min(st,temp[v1]);
            }
            pre[i][j]=st;
	    }
	}
}

int main()
{
	FastIO
	ll k,i,j,k1;
	string s;
	cin>>s>>k;
	preProcess(s);
	for(i=0;i<s.size();i++)
	    dp[i][0]=MAXN*26;
	for(i=0;i<s.size();i++){
	    for(k1=1;k1<=k+1;k1++){
	        dp[i][k1]=MAXN*26;
	        for(j=i;j>=0;j--){
                if(j==0)
                    dp[i][k1]=min(dp[i][k1],pre[j][i]);
                else dp[i][k1]=min(dp[i][k1],pre[j][i]+dp[j-1][k1-1]);
	        }
	    }
	}
	cout<<dp[s.size()-1][k+1];
	return 0;
}
