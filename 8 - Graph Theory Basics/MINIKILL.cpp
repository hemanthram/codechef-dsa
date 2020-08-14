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
#define rev(i,a,b) for(ll i=a;i>b;i--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define printn(a) cout<<a<<'\n'
#define prints(a) cout<<a<<' '
#define nl '\n'

ll leaf(ll p, ll u, vec &root, vec &ls, vector<vec> &g) {
    root[u] = p; ls[u] = 0;
    if(g[u].size() == 1 && u != 1) 
    { ls[u] = 1; return 1; }
    for(auto v:g[u]) {
        if(v == p) continue;
        ls[u] += leaf(u, v, root, ls, g);
    }
    return ls[u];
}

void leaffind(ll p, ll u, vec &ls, vec &d, vec &root, vector<vec> &g) {
    if(ls[u] == 1) { d[root[u]] = 1; return; }
    for(auto v:g[u]) {
        if(v == p) continue;
        leaffind(u, v, ls, d, root, g);
    }
}

void solve(){
    ll n,u,v,tot; cin>>n;
    vector<vec> g(n+1);
    vec root(n+1), ls(n+1), d(n+1,0);
    rep(i,0,n-1) {
        cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }
    tot = leaf(-1, 1, root, ls, g);
    if(tot == 1) { printn(1); return; }
    leaffind(-1, 1, ls, d, root, g);
    ll ans = 0;
    rep(u,1,n+1) {
        if(d[u] == 0) continue;
        ll lf=0, nlf=0;
        for(auto v:g[u]) {
            if(v == root[u]) continue;
            if(ls[v] == 1) lf += 1;
            else nlf += 1;
        }
        if(nlf > 0) ans += lf;
        else ans += (lf-1);
    }
    printn(ans);
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