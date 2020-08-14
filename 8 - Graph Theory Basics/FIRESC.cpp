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
const ll N = 100004, M = 1000000007;
ll c;
vector<vec> g;
bool vis[N];

void dfs(ll u) {
    c += 1;
    for(auto v: g[u]){
        if(vis[v]) continue;
        vis[v] = true;
        dfs(v);
    }
}

void solve(){
    ll n,m,i,j,ans=0, pro=1; cin>>n>>m;
    g.resize(n+1);
    rep(k,0,m) {
        cin>>i>>j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    fill(vis, vis+n+1, false);
    rep(i,1,n+1) {
        if(vis[i]) continue;
        c = 0; vis[i]=true; dfs(i);
        pro = (pro*c)%M;
        ans += 1;
    }
    cout<<ans<<' '<<pro<<'\n';
    g.clear();
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