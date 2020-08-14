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

void dfs(ll u, vector<bool> &exp, vector<vec> &g, ll &c, ll &mn, ll &mx, ll d, ll &tot) {
    c += 1; mx = max(mx, u); mn = min(mn,u); tot += d;
    for(auto v:g[u]) {
        if(exp[v]) continue;
        exp[v] = true;
        dfs(v, exp, g, c, mn, mx, d+1, tot);
    }
}

void solve(){
    ll n,m,u,v,c,mn,mx,tot,s; cin>>n>>m;
    vector<vec> g(n+1);
    rep(i,0,m) {
        cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }
    vector<bool> exp(n+1, false), vis(n+1, false);
    vec depth(n+1, 1); ll ans[2] = {0,0};
    rep(i,1,n+1) {
        if(exp[i]) continue;
        exp[i] = true; c =0; mx = -1; mn = n+1; 
        dfs(i, exp, g, c, mn, mx, 1, tot);
        if(c%2 == 0) s = mn; else s = mx; tot = 0; 
        vis[s] = true; 
        dfs(s, vis, g, c, mn, mx, 1, tot);
        ans[(c/2)%2] += tot;
    }
    cout<<ans[0]<<' '<<ans[1]<<'\n';
}

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return(0);
}