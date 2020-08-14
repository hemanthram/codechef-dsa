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
    string s,t,e; cin>>s>>t;
    ll m; cin>>m;
    vector<vec> g(26);
    vector<set<ll>> p(26);
    rep(i,0,m) {
        cin>>e;
        g[int(e[0])-'a'].pb(int(e[3])-'a'); 
    }
    bool vis[26]; stack<ll> st; 
    rep(i,0,26) {
        rep(j,0,26) vis[j] = false;
        st.push(i); vis[i] = true; p[i].insert(i);
        while(!st.empty()){
            ll u = st.top(); st.pop();
            for(auto v:g[u]) {
                if(vis[v]) continue;
                p[i].insert(v);
                vis[v] = true;
                st.push(v);
            }
        }
    }
    if(s.length() != t.length()) { cout<<"NO\n"; return; }
    ll n = s.length(); bool res = true;
    rep(i,0,n) {
        if(p[int(s[i])-'a'].find(int(t[i])-'a') == p[int(s[i])-'a'].end()) {
            res = false; break;
        }
    }
    if(res) cout<<"YES\n";
    else cout<<"NO\n";
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