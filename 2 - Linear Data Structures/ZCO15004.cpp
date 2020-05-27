// g++ file.cpp -o file | file
// ram learns c++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define vec vector<ll>
#define pb  push_back
#define pai pair<ll,ll>
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
ll M = pow(10,9)+7;
const ll N = 100001;

void solve(){
    ll n,t1,t2,mx=0;
    vec x(N,500), l(N,0), r(N,0);
    cin>>n;
    stack<ll> sr,sl;
    rep(i,0,n) {
        cin>>t1>>t2;
        if(t2 < x[t1]) x[t1] = t2;
    }
    rep(i,0,N) {
        while(!sr.empty() && x[sr.top()] > x[i]){
            r[sr.top()] = i;
            sr.pop();
        } sr.push(i);
        while(!sl.empty() && x[sl.top()] > x[N-i-1]){
            l[sl.top()] = N-i-1;
            sl.pop();
        } sl.push(N-i-1);
    }
    while(!sr.empty()) {r[sr.top()] = N-1; sr.pop();}
    while(!sl.empty()) {l[sl.top()] = 0; sl.pop();}
    rep(i,0,N){
        ll area = x[i]*(r[i]-l[i]);
        if(area > mx) mx = area;
    }
    cout<<mx;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
