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
const ll N = 100001,M=1000000007;
ll n,a0,a1,b0,b1,os,zs,mn,ans;
string a,b;

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

ll fac[N], invfac[N]; 
void factorial() {
    fac[0] = 1;
    rep(i,1,N) fac[i] = (fac[i-1]*i)%M;
}
void invfactorial() {
    invfac[N-1] = power(fac[N-1],M-2,M);
    for(ll i= N-2; i >= 0; --i) invfac[i] = (invfac[i+1]*(i+1))%M;
    invfac[0] = invfac[1];
}

ll nCr (ll n, ll r) {
    ll p = fac[n];
    p = (p*(invfac[r]))%M;
    p = (p*(invfac[n-r]))%M;
    return p;
}

void solve(){
    cin>>n;
    cin>>a>>b;
    a0 = a1 = b0 = b1 = 0;
    rep(i,0,n){
        if(a[i] == '1') a1 += 1;
        else a0 += 1;
        if(b[i] == '1') b1 += 1;
        else b0 += 1;
    }
    os = min(a1,b1); zs = min(a0,b0);
    mn = max(a1,b1) - min(a1,b1);
    ll tmp, nm=n-mn+1, dm=mn;
    tmp = nCr(n,mn);
    ans = tmp%M;
    rep(i,0,min(os,zs)){
        mn += 2;
        ans = (nCr(n,mn) + ans)%M;
    }
    cout<<ans<<endl;
}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    factorial();
    invfactorial();
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
