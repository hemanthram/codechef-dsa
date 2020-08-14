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
ll c, g[1000][1000],n,m,s,ms,mx;
bool vis[1000][1000];

void dfs(ll x, ll y) {
    c += 1;
    if(x>0 && g[x-1][y] == g[x][y] && !vis[x-1][y]) { vis[x-1][y] = true; dfs(x-1,y); }
    if(x<n-1 && g[x+1][y] == g[x][y] && !vis[x+1][y]) { vis[x+1][y] = true; dfs(x+1,y); }
    if(y>0 && g[x][y-1] == g[x][y] && !vis[x][y-1]) { vis[x][y-1] = true; dfs(x,y-1); }
    if(y<m-1 && g[x][y+1] == g[x][y] && !vis[x][y+1]) { vis[x][y+1] = true; dfs(x,y+1); }
}

void solve(){
    cin>>n>>m; ms = LONG_LONG_MAX; mx=0;
    rep(i,0,n) rep(j,0,m) { cin>>g[i][j]; vis[i][j] = false; }
    rep(i,0,n) rep(j,0,m) {
        if(vis[i][j]) continue;
        c = 0; vis[i][j]=true; dfs(i,j); s = g[i][j]; 
        if(mx < c) { mx=c; ms=s; }
        if(mx == c) { if(s < ms) ms=s; }
    }
    cout<<ms<<' '<<mx<<'\n';
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