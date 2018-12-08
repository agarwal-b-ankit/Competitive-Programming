#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
	int n,i,j=0,len;
	cin>>n;
	LL x,sum,a[n];
	cin>>x;
	for(i=0;i<n;i++)
        cin>>a[i];
    i=0;
    sum=a[0];
    len=n+1;
    while(i<n)
    {
        if(sum<=x)
        {
            if(j==n-1)
                break;
            sum+=a[++j];
        }
        while(sum>x)
        {
            len=min(len,j-i+1);
            sum-=a[i++];
        }
    }
    cout<<len-1;
	return 0;
}
