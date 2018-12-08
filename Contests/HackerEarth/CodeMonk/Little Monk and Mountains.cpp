#include <bits/stdc++.h>
using namespace std;
#define LL long long

bool myfun(pair<LL,LL> p1, pair<LL,LL> p2)
{
    return p1.second<=p2.second;
}

int main()
{
	int n,q,i;
	cin>>n>>q;
	LL x,y,cnt[n],ans;
	vector<pair<LL,LL> > a;
	vector<LL> ar(n,0);
	for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
        if(i!=0)
            ar[i]=ar[i-1]+y-x+1;
        else ar[i]=y-x+1;
    }
    //sort(ar.begin(),ar.end());
    while(q--)
    {
        cin>>x;
        LL val=lower_bound(ar.begin(),ar.end(),x)-ar.begin();
            ans=a[val].first+x-1;
            if(val!=0)
                ans-=ar[val-1];
        cout<<ans<<endl;
    }
	return 0;
}
