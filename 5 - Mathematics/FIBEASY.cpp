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

vec a = {0,1};
void solve(){
    ll n;
    cin>>n;
    ll l = 0, p=2;
    while(p <= n) {
        l += 1;
        p *= 2;
    }
    cout<<a[(power(2,l,60)-1)]<<endl;
}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    ll t=1;
    cin>>t;
    rep(i,2,100) a.pb((a[i-1]+a[i-2])%10); 
    while(t--)
    solve();
    return 0;
}
