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
const ll N = 100005;
ll parent[N], size[N];
bool res;

ll find_set(ll x) {
    if(x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}
void make_set(ll x) { parent[x]=x; size[x]=1; }
void union_set(ll x, ll y) {
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
    if(size[x] < size[y]) swap(x,y);
    parent[y] = x;
    size[x] += size[y];
}

void dfs(ll u, ll c, vector<bool> &exp, vector<vec> &g, vec &color) {
    color[u] = c; c^=1;
    for(auto v:g[u]) {
        if(exp[v]) { if(color[v] != c) res = false; continue; }
        exp[v] = true;
        dfs(v, c, exp, g, color);
    }
}

void solve(){
    ll n,Q,i,j,q; cin>>n>>Q;
    rep(i,0,n) make_set(i+1);
    vector<pai> d;
    rep(k,0,Q) {
        cin>>i>>j>>q;
        if(q == 0) union_set(i,j);
        else d.push_back({i,j});
    }
    vec color(n+1,-1);
    vector<vec> g(n+1);
    vector<bool> exp(n+1,false);
    rep(k,0,d.size()) {
        i = d[k].F; j = d[k].S;
        i = find_set(i); j = find_set(j);
        if(i == j) { printn("no"); return; }
        g[i].pb(j); g[j].pb(i);
    } res = true;
    rep(u,1,n+1) {
        if(exp[u]) continue;
        exp[u] = true;
        dfs(u, 0, exp, g, color);
        if(!res) break;
    }
    if(res) printn("yes");
    else printn("no");
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