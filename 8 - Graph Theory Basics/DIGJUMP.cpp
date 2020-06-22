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

void solve(){
    string s; cin>>s;
    ll n = s.length(),t;
    if(n == 1) {cout<<0; return;}
    vec a, ans(n,n) ,c, tmp; stack<ll> fill;
    vector<bool> h(10,false);
    rep(i,0,n) a.push_back(int(s[i])-'0'); 
    ans[0]=0; c.pb(a[0]); t=1; h[a[0]] = true;
    while(ans[n-1] == n){
        rep(i,1,n) 
        if(ans[i] == n){
            if(i>0 && ans[i-1] != n) {
                if(!h[a[i]]) { h[a[i]] = true; tmp.pb(a[i]); }
                fill.push(i);
            }
            if(i<(n-1) && ans[i+1] != n) {
                if(!h[a[i]]) { h[a[i]] = true; tmp.pb(a[i]); }
                fill.push(i);
            }
        }
        while(!fill.empty()) {ans[fill.top()] = t; fill.pop();}
        for(auto j:c) rep(k,0,n) if(a[k] == j && ans[k] == n) ans[k]=t;
        c = tmp; tmp.clear(); t += 1;
    }
    cout<<ans[n-1];
}

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif

    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return(0);
}