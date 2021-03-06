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
#define print(x) cout<<x<<endl

ll power(ll x, ll y, ll p){ 
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}
ll M = 100002;

void solve(){
    ll n,inp;
    vec b,zp; b.pb(0); zp.pb(0);
    cin>>n;
    rep(i,0,n) {
        cin>>inp;
        if(inp == 1) b.pb(1);
        else b.pb(-1);
    }
    rep(i,1,n+1) b[i] = b[i]+b[i-1];
    ll mx=0,st, ms=0, ss=0;
    rep(i,1,n+1) {
        if(b[i] > mx) {mx = b[i]; st = i;}
        if(b[i] == 0) zp.pb(i);
    }
    rep(i,0,zp.size()-1){
        if(zp[i+1]-zp[i] > ms) {ms = zp[i+1]-zp[i]; ss = zp[i]+1;}
    }
    cout<<mx<<' '<<st<<' '<<ms<<' '<<ss;

}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
