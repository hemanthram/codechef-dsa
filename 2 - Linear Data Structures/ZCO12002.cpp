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
ll M = pow(10,9)+7;
const ll N = 1000005;

void solve(){
    ll n,x,y,t1,t2,mn=LONG_LONG_MAX;
    cin>>n>>x>>y; vec v, w;
    vector<pai> p;
    rep(i,0,n) {
        cin>>t1>>t2;
        p.pb({t1,t2});
    }
    rep(i,0,x) {cin>>t1; v.pb(t1);} sort(all(v));
    rep(i,0,y) {cin>>t1; w.pb(t1);} sort(all(w));
    ll l,r;
    rep(i,0,n) {
        l = upper_bound(all(v),p[i].F)-v.begin();
        if(l == 0) continue; l-=1;
        r = lower_bound(all(w),p[i].S)-w.begin();
        if(r == y) continue;
        if((w[r]-v[l]+1) < mn) mn = w[r]-v[l]+1;
    }    
    cout<<mn;
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
