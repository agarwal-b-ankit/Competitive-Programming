#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define INF 1e18
#define mod 1000000007
#define lim 1000001
#define sz(a) int(a.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//#define tr(c,it) for(typeof((c).begin() it = (c).begin(); it != (c).end(); it++)

int fin(vector<int> &par, vector<int> &ran, int i){
    if(par[i]!=i){
        par[i]=fin(par,ran,par[i]);
    }
    return par[i];
}

int uni(vector<int> &par, vector<int> &ran, int i, int j){
    if(i==0) return j;
    if(j==0) return i;
    int pi=fin(par,ran,i);
    int pj=fin(par,ran,j);
    if(pi==pj) return pi;
    if(ran[pi]<ran[pj]){
        par[pi]=pj;
        ran[pj]++;
        return pj;
    } else{
        par[pj]=pi;
        ran[pi]++;
        return pi;
    }
}

int main()
{
    ll t,n,i,j;
    string s;
    cin>>s;
    vector<int> par(s.length()+1,0),ran(s.length()+1,0);
    for(i=0;i<=s.length();i++) par[i]=i;
    stack<pair<int,int> > st;
    for(i=s.length();i>0;i--){
        if(s[i-1]=='?'){
            st.push(mp(i,0));
        } else {
            pair<int,int> lv=st.top();st.pop();
            pair<int,int> rv=st.top();st.pop();
            if(s[i-1]=='+'){
                st.push(mp(uni(par,ran,lv.ff,rv.ff),uni(par,ran,lv.ss,rv.ss)));
            } else {
                st.push(mp(uni(par,ran,lv.ff,rv.ss),uni(par,ran,lv.ss,rv.ff)));
            }
        }
    }
    pair<int,int> fi=st.top();
    int pos=0,neg=0;
    for(i=1;i<=s.length();i++){
        if(fin(par,ran,i)==fi.ff)
            pos++;
        else if(fin(par,ran,i)==fi.ss)
            neg++;
    }
    if(pos<neg){
        tie(pos,neg)=make_tuple(neg,pos);
        fi=mp(fi.ss,fi.ff);
    }
    int div=pos/neg;
    int rem=pos%neg;
    for(i=1;i<=s.length();i++){
        if(fin(par,ran,i)==fi.ss){
            if(rem){
                cout<<div+1<<endl;
                rem--;
            } else{
                cout<<div<<endl;
            }
        } else if(fin(par,ran,i)==fi.ff)
            cout<<1<<endl;
    }
    return 0;
}
