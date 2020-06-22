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
    ll n, mx=0; cin>>n;
    vec a(n); rep(i,0,n) cin>>a[i];
    rep(i,0,n-3) {
        if(a[i]+a[i+1]+a[i+2] > mx) mx = a[i]+a[i+1]+a[i+2];
    }
    mx = max(a[n-1]+a[0]+a[1], mx);
    mx = max(a[n-2]+a[n-1]+a[0],mx);
    cout<<mx<<endl;
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