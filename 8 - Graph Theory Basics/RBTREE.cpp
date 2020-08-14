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
#define printn(a) cout<<a<<'\n'
#define prints(a) cout<<a<<' '
#define nl '\n'
ll c = 0;

void solve(){
    string s; cin>>s;
    if(s == "Qi") { c^=1; return; }
    ll x,y,lx=0,ly=0,nc=0; cin>>x>>y;
    stack<ll> qx,qy;
    while(x) { qx.push(x); x /= 2; lx+=1; }
    while(y) { qy.push(y); y /= 2; ly+=1; }
    ll lca = 1, l=0;
    while(!qx.empty() && !qy.empty()) {
        if(qx.top() == qy.top()) lca = qx.top();
        else break;
        qx.pop(); qy.pop(); l+=1;
    }
    while(!qx.empty()) qx.pop();
    while(!qy.empty()) qy.pop();
    nc = 1 + ((lx-l)/2) + ((ly-l)/2);
    ll a[2];
    a[0] = nc; a[1] = lx+ly-(2*l)+1-nc;
    
    if(s == "Qb") {
        if(l%2) prints(a[c]);
        else prints(a[c^1]);
    }
    if(s == "Qr") {
        if(l%2) prints(a[c^1]);
        else prints(a[c]);
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