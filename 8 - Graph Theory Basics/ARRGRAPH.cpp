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

vec p;
void primes() {
    vector<bool> exp(51,false);
    rep(i,2,50) {
        if(exp[i]) continue;
        p.push_back(i);
        ll j = i;
        while(j <= 50) 
        { exp[j] = true; j += i; }
    }
}

ll binp(ll x) {
    ll y = 0, tmp = 1;
    rep(i,0,p.size()) {
        if(x%p[i] == 0) y += tmp;
        tmp *= 2;
    }
    return y;
}

void dfs(ll u, vector<bool> &exp, vector<vec> &g) {
    for(auto v:g[u]) {
        if(exp[v]) continue;
        exp[v] = true;
        dfs(v, exp, g);
    }
}

void solve(){
    ll n; cin>>n;
    vec a(n), bp(n);
    vector<vec> g(n);
    rep(i,0,n) { cin>>a[i]; bp[i] = binp(a[i]); }
    rep(i,0,n-1) rep(j,i+1,n) {
        if((bp[i]&bp[j]) == 0) { 
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    vector<bool> exp(n,false);
    ll cc = 0;
    rep(i,0,n) {
        if(exp[i]) continue;
        cc += 1; exp[i] = true;
        dfs(i, exp, g);
    }    
    bool res = false;
    if(cc == 1) { res = true; }
    else {
        ll o = 0, rp;
        rep(i,0,n) o |= bp[i];
        rep(i,0,p.size()) 
        if(o%2 == 0) { rp =  p[i]; break; }
        else o /= 2;
        a[0] = rp;
    }
    if(res) printn(0); else printn(1);
    rep(i,0,n) prints(a[i]); printn(' ');
}

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    primes();
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return(0);
}