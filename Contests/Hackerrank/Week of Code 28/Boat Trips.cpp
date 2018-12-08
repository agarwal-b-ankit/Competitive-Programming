#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,c,m,ma=0,var;
    cin>>n>>c>>m;
    for(int i=0;i<n;i++)
        {
        cin>>var;
        if(var>ma)
            ma=var;
    }
    if(ma<=m*c)
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
