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
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.length();i++)
        if(s[i]=='_')
            cnt++;
	cout<<cnt+1;
	return 0;
}
