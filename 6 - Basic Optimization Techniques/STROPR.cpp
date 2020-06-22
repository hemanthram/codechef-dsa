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
const ll N = 100005, M = 1000000007;
ll a[N];

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

void solve(){
    ll n,x,m,ans=0; cin>>n>>x>>m; 
    rep(i,0,n) { cin>>a[i]; a[i]%=M; } 
    if(m == 1) {
        rep(i,0,x) ans = (ans+a[i])%M;
        cout<<ans<<endl;
        return;
    } 
    ll num = 1, den = 1, t = 1, tmp;
    for (ll i = x-1; i>=0 ; --i){
        tmp = (num*(power(den,M-2,M)))%M;
        ans = (ans + (a[i])*tmp )%M;
        num = (num*( (m+t-1)%M ))%M;
        den = (den*t)%M;
        t += 1;
    }
    cout<<ans<<endl;
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