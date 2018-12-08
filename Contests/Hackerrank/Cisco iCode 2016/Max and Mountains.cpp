#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

long long dis(long long n)
{
    int ans=0;
    for(int i=1;i<=floor(sqrt(n));i++)
        if(n%i==0)
            ans++;
    ans*=2;
    if(sqrt(n)==(int)sqrt(n))
        ans--;
    return ans;
}

int main()
{
	int n,m,i;
	cin>>n;
	long long a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    vector<long long> v;
    for(i=0;i<n;i++)
    {
        v.push_back(dis(a[i]));
    }
    sort(v.begin(),v.end());
    long long sum=0,j;
    for(j=0;j<n;j++)
    {
        sum+=v[j];
        if(sum>m)
            break;
    }
    cout<<j;
	return 0;
}
