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
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
ll INF=numeric_limits<ll>::max();
const ll MAXN=100010;
 
double a1,b1,a2,b2,r;
double pi2=acos(0);
 
double cal(double theta){
    double dis1=sqrt(pow(a1-r*cos(theta),2)+pow(b1-r*sin(theta),2));
    double dis2=sqrt(pow(a2-r*cos(theta),2)+pow(b2-r*sin(theta),2));
    return dis1+dis2;
}
 
double solve(double low, double high){
    double mid=low;
    if(high-low>0)
        mid+=(high-low)/2;
    else mid+=(4*pi2-low+high)/2;
    if(mid>4*pi2)
        mid-=4*pi2;
    if(high-low<=0.0000001) return cal(mid);
    if(cal(low)<cal(high))
        return solve(low,mid);
    else return solve(mid,high);
}
 
pair<double,double> slope(double a, double b){
    double theta=atan(sqrt(a*a+b*b-r*r)/r);
    double temp1,temp2;
    if(a>=0 && b>=0){
        if(a==0)
            temp1=pi2+theta,temp2=pi2-theta;
        else
            temp1=atan(b/a)+theta,temp2=atan(b/a)-theta;
    } else if(b>=0){
        temp1=pi2+atan(-b/a)+theta,temp2=pi2+atan(-b/a)-theta;
    } else if(a>=0){
        if(a==0)
            temp1=3*pi2+pi2+theta,temp2=3*pi2+pi2-theta;
        else
            temp1=3*pi2+atan(-b/a)+theta,temp2=3*pi2+atan(-b/a)-theta;
    } else {
        temp1=2*pi2+atan(b/a)+theta,temp2=2*pi2+atan(b/a)-theta;
    }
    if(temp1<0) temp1=4*pi2+temp1;
    if(temp2<0) temp2=4*pi2+temp2;
    if(temp1>=4*pi2) temp1-=4*pi2;
    if(temp2>=4*pi2) temp2-=4*pi2;
    return {temp2,temp1};
}
 
pair<double,double> slope1(double a, double b){
    double temp1,temp2;
    if(a==0 && b>=0)
        temp1=pi2;
    else if(a==0)
        temp1=3*pi2;
    else if(a>0 && b>=0)
        temp1=atan(b/a);
    else if(a>0)
        temp1=3*pi2+atan(-b/a);
    else if(b>=0)
        temp1=pi2+atan(-b/a);
    else temp1=2*pi2+atan(b/a);
    return {temp1,temp1};
}
 
pair<double,double> check(pair<double,double> m1,pair<double,double> m2){
    double rot=4*pi2-m1.ff;
    pair<double,double> ans={-1,-1};
    m1.ff=0;
    m1.ss+=rot;
    if(m1.ss>=4*pi2) m1.ss-=4*pi2;
    m2.ff+=rot;
    if(m2.ff>=4*pi2) m2.ff-=4*pi2;
    m2.ss+=rot;
    if(m2.ss>=4*pi2) m2.ss-=4*pi2;
    
    if(m2.ss>m1.ss && m2.ff<m1.ss){
        ans.ff=m2.ff+4*pi2-rot;
        if(ans.ff>=4*pi2) ans.ff-=4*pi2;
        ans.ss=m1.ss+4*pi2-rot;
        if(ans.ss>=4*pi2) ans.ss-=4*pi2;
    } else if(m2.ss<m1.ss && m2.ff<m1.ss){
        ans.ff=m2.ff+4*pi2-rot;
        if(ans.ff>=4*pi2) ans.ff-=4*pi2;
        ans.ss=m2.ss+4*pi2-rot;
        if(ans.ss>=4*pi2) ans.ss-=4*pi2;
    } else if(m2.ff>m1.ss && m2.ss<m1.ss){
        ans.ff=m1.ff+4*pi2-rot;
        if(ans.ff>=4*pi2) ans.ff-=4*pi2;
        ans.ss=m2.ss+4*pi2-rot;
        if(ans.ss>=4*pi2) ans.ss-=4*pi2;
    } else if(m2.ff>m1.ss && m2.ss>m1.ss && m2.ss<m2.ff){
        ans.ff=m1.ff+4*pi2-rot;
        if(ans.ff>=4*pi2) ans.ff-=4*pi2;
        ans.ss=m1.ss+4*pi2-rot;
        if(ans.ss>=4*pi2) ans.ss-=4*pi2;
    }
 
    return ans;
}
 
int main()
{
	//FastIO
	cout<<fixed;
	cout<<setprecision(6);
	cin>>a1>>b1>>a2>>b2>>r;
	bool flag=false;
	double x,y,k;
	if(b1==b2){
	    if(b1>r || a1*a2>0)
	        flag=true;
	    x=0,y=b1;
	} else if(a1==a2){
	    if(a1>r || b1*b2>0)
	        flag=true;
	    x=a1,y=0,k=0;
	} else{
	    k=(a1-a2)/(b2-b1);
	    x=(k*b1+a1)/(1+k*k);
	    y=k*x;
	    if((y*y+x*x>r*r) || (y-b1)*(x-a1)*(y-b2)*(x-b2)>0)
	        flag=true;
	}
	pair<double,double> ma=slope(a1,b1),mb=slope(a2,b2);
	pair<double,double> ans=check(ma,mb);
	if(flag){
	    //cout<<solve(min(ma.ff,mb.ff),max(ma.ff,mb.ff));
	    cout<<solve(ans.ff,ans.ss);
	} else{
	    
	    double kslope=(x==0)?pi2:atan(abs(k));
    	if((x==0 && y<0) || (x>0 && k<0))
    	    kslope+=2*pi2;
        if(abs(kslope-ma.ff)>=abs(kslope-ma.ss))
            swap(ma.ff,ma.ss);
        if(abs(kslope-mb.ff)>=abs(kslope-mb.ss))
            swap(mb.ff,mb.ss);
        double tabs=abs(mb.ff-ma.ff);
        tabs=min(min(abs(ma.ff-mb.ff),abs(ma.ff-mb.ss)),min(abs(ma.ss-mb.ff),abs(ma.ss-mb.ss)));
        if(tabs>2*pi2)
            tabs=4*pi2-tabs;
        else if(tabs==0)
            tabs=2*pi2;
        double arc=r*tabs;
    	
	    double t1=sqrt(a1*a1+b1*b1-r*r),t2=sqrt(a2*a2+b2*b2-r*r);
	    double ans=t1+t2+arc;
	    cout<<ans;
	}
	return 0;
}