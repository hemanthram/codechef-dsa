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
const ll N = 100005, L = 19;

void dfs(ll u, ll p, vector<vec> &g, vector<vec> &dp, vec &eu, vec &h) {
    dp[u][0] = p; eu.push_back(u);
    rep(i,1,L) { dp[u][i] = dp[dp[u][i-1]][i-1]; }
    for(auto v:g[u]) {
        if(v == p) continue;
        h[v] = h[u] + 1;
        dfs(v,u,g,dp,eu,h);
    } eu.push_back(u);
}

bool isancestor(ll u, ll v, vec &ti, vec &to) 
{ return ((ti[u] <= ti[v]) && (to[u] >= to[v])); }

ll lca(ll u, ll v, vector<vec> &dp, vec &ti, vec &to) {
    if(isancestor(u,v,ti,to)) return u;
    if(isancestor(v,u,ti,to)) return v;
    rev(i, L-1, -1) {
        if(!isancestor(dp[u][i], v, ti, to))
        u = dp[u][i];
    }
    return dp[u][0];
}

void solve(){
    ll n,u,v,q; cin>>n>>q;
    vector<vec> g(n+1), dp(n+1, vec (L,0));
    vec a(n+1); rep(i,0,n) cin>>a[i+1];
    vec h(n+1), ti(n+1,-1), to(n+1,2*n), eu;
    rep(i,0,n-1) {
        cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }
    h[1] = 1; dfs(1,0,g,dp,eu,h);
    rep(i,0,2*n) if(ti[eu[i]] == -1) ti[eu[i]] = i; else to[eu[i]] = i;
    vec xorp(2*n+1,0);
    rep(i,0,2*n) xorp[i+1] = xorp[i]^a[eu[i]];
    rep(i,0,q) {
        ll l,u,v; cin>>u>>v;
        l = lca(u,v,dp,ti,to);
        ll x = xorp[ti[v]+1]^xorp[ti[u]+1];
        ll ans = x^a[l];
        printn(ans);
    }
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