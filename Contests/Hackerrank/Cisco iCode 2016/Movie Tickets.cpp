#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n,x,y;
	cin>>n>>y>>x;
    if(y==0)
        cout<<x;
    else
    {
        int ans=y*(n+1);
        if(y%2==0)
            ans+=x;
        else
            ans+=n-x;
        cout<<ans;
    }
	return 0;
}
